//
// Created by Alex on 10/9/18.
//

#include "Exception.h"

Exception::Exception(const char *str)
{
    this->str = str;
}

Exception::~Exception() = default;

const char *Exception::what() const noexcept
{
    return str;
}
