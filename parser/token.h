#pragma once

using namespace std;

struct Token
{
    int LineNumber;
    string Source;
    string Lexeme;
    enum Type
    {
        identifier = 0,
        shout = 1,
        number = 2
    };
};