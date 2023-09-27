#include "value.h"
#include "myFunctions.h"
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

Value::Value(float v): val(v), grad(0) {}

float Value::get_grad() const{
    return grad;
}

float Value::get_value(){
    return grad;
}

Value Value::operator+(Value& other) {
    Value out{val + other.val};
    out.children.insert(this);
    out.children.insert(&other);
    //may not actually want the refrence but we shall see
    //can always create pointers or just copy the vals
    out.my_back = [this,&other,&out](){
        this->grad += out.grad;
        other.grad += out.grad;
    };
    return out;
}

Value Value::operator+(const float& other) {
    Value val_other{other};
    return *this + val_other;
}

//Okay what i'm going to have to do is pass out.grad as
Value Value::operator*(Value& other) {
    Value out{val * other.val};
    out.children.insert(this);
    out.children.insert(&other);

    out.my_back = [this,&other,&out](){
        this->grad += other.val * out.grad;
        other.grad += this->val * out.grad;

    };
    return out;
}

Value Value::operator*(const float& other) {
    Value val_other{other};
    return *this * val_other;
}

Value Value::operator-() {
    return *this * -1;
}

Value Value::operator-(Value& other) {
    return {-other + *this};
}

Value Value::operator-(float& other) {
    Value val_other{other};
    return *this - val_other;
}

Value Value::operator/(Value& other) {
    Value temp{power(*this, -1)};
    return power(*this, -1) * other;
}

void Value::build_topo(Value* v, std::vector<Value*>& topo,
                       std::set<Value*>& visited){
    if (visited.find(v) == visited.end()){
        visited.insert(v);
        for (const auto& child : v->children){
            build_topo(child, topo,visited);
        }
        topo.push_back(v);
    }
}

//NOTE: if not a value in memory pass copy to lambda func
//Should probably try and impliment it as a function as well
Value Value::tanh_h() {
    float t = std::tanh(val);
    Value out{t};
    out.children.insert(this);
    out.my_back = [this, &out, t](){
        this->grad += (1 - (t * t)) * out.grad;
    };
    return out;
}

/*
 Value tan_h(Value& myVal){
    float val = myVal.val;
    float x = std::tanh(val);
    Value out{x};
    out.children.insert(&myVal);
    out.my_back = [&myVal, &x, &out](){
        myVal.grad += 1- (x * x) * out.grad;
    };
    return myVal;
}
 */
/*
Value relu(Value& myVal) {
    Value out{(myVal.val > 0) ? myVal.val : 0};
    out.children.insert(&myVal);
    out.my_back = [&out, &myVal]() {
        myVal.grad += (myVal.val > 0) ? myVal.val * out.grad : 0;
    };
    return out;
}
 */


void Value::backward() {
   std::vector<Value*> topo;
   std::set<Value*> visited;

   build_topo(this,topo,visited);

   this->grad = 1;
   std::reverse(topo.begin(),topo.end());

   for (auto v: topo){
       //std::cout << "memory address: " << v << " is in topo\n";
       v->my_back();
   }
}

std::ostream& operator<<(std::ostream& os, const Value& myVal) {
    os << "Value: " << myVal.val << " Grad: " << myVal.grad << "\n";
    return os; // You need to return the ostream object.
}

