#pragma once
#include <string>
#include "parser/token.h"
#include <vector>
class Scanner
{

public:
    Scanner();
    std::vector<Token> scan(string inString);
};