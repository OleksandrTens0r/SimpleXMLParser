//
// Created by Alex on 10/9/18.
//

#ifndef TASK_PARSER_H
#define TASK_PARSER_H

#include <iostream>
#include <fstream>
#include "vector"

class TestParser;

class Parser
{
private:
    friend TestParser;

    std::string path;

    std::ofstream fout;

    std::ifstream fin;

    std::vector<int> parseSequence(unsigned int low, unsigned int high);

    void writeInFile(std::vector<int> primerList);

    void isPositive(int& bound);

    void isCorrect(int low, int high);
public:
    explicit Parser();

    void parse(const std::string &path);
};


#endif //TASK_PARSER_H
