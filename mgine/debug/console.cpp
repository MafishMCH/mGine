#include "console.hpp"
#include "performance.hpp"

#include <stdarg.h>

Console console;

void Console::clear()
{
    for(auto& line : lines)
        line = "";
    updateDiagnostics();
}

void Console::writeLine(const char*fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    char buffer[64];
    int len = vsprintf(buffer, fmt, args);
    buffer[len] = '\n';
    buffer[len+1] = 0; 
    va_end(args);

    if(lines.size() >= maxLines)
        lines.pop_front();
    lines.emplace_back(buffer);
}

std::string Console::getString()
{
    std::string result(diagnosticsLine);
    for(auto& line : lines)
    {
        result.append(line);
    }
    return result;
}
void Console::updateDiagnostics()
{
    diagnosticsLine = std::string("FPS: " + std::to_string((int)Performance::getFps()) + "\n");
}
