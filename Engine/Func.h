#ifndef FUNC_H
#define FUNC_H

#include <vector>
#include <string>

class Func
{
    public:
    Func();
    static std::vector<std::string> Split(const std::string &s, char delim);
    template<typename T> static std::string to_str(const T& t);
};

#endif // FUNC_H
