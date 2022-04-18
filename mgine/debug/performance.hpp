#pragma once

#include <cstdint>

class Performance
{
private:
    inline static uint32_t lastFrameTs = 0;
    inline static int msPerFrame = 0;
    inline static float fps = 0.0f;
public:
    inline static void updatePerFrame(uint32_t timestamp)
    {
        msPerFrame = timestamp - lastFrameTs;
        lastFrameTs = timestamp;
        fps = fps * 0.9f + (1000.0f / (float)msPerFrame) * 0.1f;
    }
    inline static float getFps()
    {
        return fps;
    }
};