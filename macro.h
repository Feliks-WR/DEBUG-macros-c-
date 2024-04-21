#pragma once

#ifndef LOG_H_
#define LOG_H_

#ifdef NDEBUG

#define LOG(...) ((void)0)

#else // !defined(NDEBUG)

#define LOG(msg, ...) ::NS::log(msg, __VA_ARGS__)

#endif // NDEBUG

namespace NS {
    static inline void log(const char* const str, auto args)
    {
        std::clog << str;
        std::clog << args;
        std::clog << std::endl;
    }

    static inline void log(auto str)
    {
        std::clog << str;
        std::clog << std::endl;
    }
}


#endif // !LOG_H_
