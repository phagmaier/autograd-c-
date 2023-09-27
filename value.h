#ifndef CYTORCH2_VALUE_H
#define CYTORCH2_VALUE_H

#include <set>
#include <functional>
#include <vector>
#include <algorithm>

//Delete operation
//Remeber to delete associate function 
//also you should have to call a function to set the gradient
//The default will just be 1
//Guess there are some conditions when you'd won't to actually set grad if you want to replace it with
//Another values gradient 
class Value {
public:
    //basic overload operations and constructor
    Value(float v);
    [[nodiscard]] float get_grad() const;
    float get_value();
    Value operator+(Value& other);
    Value operator*(Value& other);
    Value operator*(const float& other);
    Value operator+(const float& other);
    Value operator-();
    Value operator-(Value& other);
    Value operator-(float& other);
    Value operator/(Value& other);
    Value tanh_h();
    //Value relu();

    //backward function and helper (build_topo)
    void backward();
    void build_topo(Value* v, std::vector<Value*>& topo, std::set<Value*>& visited);

    std::function<void()> my_back = [](){}; //lambda function to update gradient
    float val;
    float grad;
    std::set<Value*> children; //nodes that created it (really they are parents)
    friend std::ostream& operator<<(std::ostream& os, const Value& myVal);
};


#endif //CYTORCH2_VALUE_H
