//
// Created by Alex on 10/9/18.
//

#ifndef TASK_EXCEPTION_H
#define TASK_EXCEPTION_H

#include <iostream>
#include <exception>

class Exception : public std::exception
{
private:
    const char* str;
public:
    explicit Exception(const char* str);

    ~Exception() override;

    const char* what() const noexcept override;
};

#endif //TASK_EXCEPTION_H
