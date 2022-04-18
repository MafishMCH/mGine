#pragma once

#include <string>
#include <deque>
class Console
{
private:
    const int maxLines = 10;
    std::string diagnosticsLine;
    std::deque<std::string> lines;
public:
    Console() {clear();};
    void writeLine(const char*fmt, ...);
    void clear();
    std::string getString();
    void updateDiagnostics();
};

extern Console console;
