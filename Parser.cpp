//
// Created by Alex on 10/9/18.
//

#include "Parser.h"
#include "Exception.h"
#include <future>
#include <thread>
#include <queue>

Parser::Parser() {}

void Parser::parse(const std::string &path)
{
    this->path = path;

    using myFuture = std::future<std::vector<int>>;

    std::string tag;

    std::queue<myFuture> results;

    int low = 0, high = 0;

    fin.open(this->path);

    if ( fin.is_open() )
    {
        while ( !fin.eof() )
        {
            fin >> tag;

            if ( tag == "<low>" )
            {
                fin >> low;
                isPositive(low);
            }

            if ( tag == "<high>" )
            {
                fin >> high;

                isPositive(high);

                try
                {
                    isCorrect(low, high);
                }
                catch ( Exception& ex )
                {
                    low = 0;
                    high = 0;
                    continue;
                }

                results.push(std::async(std::launch::async, &Parser::parseSequence,this, low, high));
            }
        }
    }
    else
    {
        throw Exception("File is not open!");
    }

    while ( !results.empty() )
    {
        writeInFile(results.front().get());
        results.pop();
    }

    fout << "</root>" << std::endl;

    fout.close();
    fin.close();
}

std::vector<int> Parser::parseSequence(unsigned int low, unsigned int high)
{
    std::vector<int> primerList(high);

    // Declare array with range 0 to high
    for (int i = 2; i < high; i++)
    {
        primerList[i] = i;
    }

    // Zero all non prime numbers
    for (int i = 2; i < high; i++)
    {
        for (int j = i*i; j < high; j += i){
            primerList[j] = 0;
        }
    }

    // Remove all numbers before low
    auto firstPrimeNumder = primerList.begin();

    std::advance(firstPrimeNumder, low);

    std::sort(firstPrimeNumder, primerList.end());

    for ( ; firstPrimeNumder != primerList.end(); ++firstPrimeNumder )
    {
        if ( *firstPrimeNumder != 0 )
        {
            break;
        }
    }

    primerList.erase(primerList.begin(), firstPrimeNumder);

    return primerList;
}

void Parser::writeInFile(std::vector<int> primerList)
{
    if ( !fout.is_open() )
    {
        fout.open("out.xml");

        fout << "<? xml version=\"1.0\" ?>" << std::endl;
        fout << "<root>" << std::endl;
    }

    fout << "   <primes> ";

    for( auto iter : primerList )
    {
        fout << iter << " ";
    }

    fout << "</primes>" << std::endl;
}

void Parser::isPositive(int& bound)
{
    if ( bound < 0 )
    {
        bound = 0;
    }
}

void Parser::isCorrect(int low, int high)
{
    if ( high < low )
    {
        throw Exception("Incorrect interval!");
    }
}
