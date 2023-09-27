#include "value.h"
#include "myFunctions.h"
#include <cmath>

Value operator+(const float& left, Value& right) {
    Value val_other{left};
    return val_other + right;
}

Value operator*(const float& left, Value& right) {
    Value val_other{left};
    return val_other * right;
}

Value operator-(const float& left, Value& right) {
    Value val_other(left);
    return val_other - right;
}

Value power(Value& value, const float& power_to) {
    Value out = Value{std::pow(value.val, power_to)};
    out.children.insert(&value);
    value.my_back = [&value, &out, &power_to]() {
        value.grad += (power_to * std::pow(value.val, (power_to - 1))) * out.grad;
    };
    return out;
}

/*
//Need to create children for the output value
Value relu(Value& myVal) {
    Value out{(myVal.val > 0) ? myVal.val : 0};
    out.children.insert(&myVal);
    out.my_back = [&out, &myVal]() {
        myVal.grad += (myVal.val > 0) ? myVal.val * out.grad : 0;
    };
    return out;
}
 */

//This is fucking up for some reason

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



