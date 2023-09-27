//
// Created by Parker Hagmaier on 9/11/23.
//

#ifndef CYTORCH_MYFUNCTIONS_H
#define CYTORCH_MYFUNCTIONS_H

#include "value.h"

Value operator+(const float& left, Value& right);
Value operator*(const float& left, Value& right);
Value operator-(const float& left, Value& right);
Value power(Value& value, const float& power_to);
//Value relu(Value& myVal);
//Value tan_h(Value& myVal);

#endif //CYTORCH_MYFUNCTIONS_H
