#pragma once

#ifndef LOG_H_
#define LOG_H_

#ifdef NDEBUG

#define LOG_DBG(...) ((void)0)
#define ERR_DBG(...) ((void)0)

#else // !defined(NDEBUG)

#define LOG_DBG(fmt, ...) ::NS::write(stdout, fmt, __VA_ARGS__)
#define ERR_DBG(fmt, ...) ::NS::write(stderr, fmt, __VA_ARGS__)

#endif // !NDEBUG

#include <iostream>
#include <cstdarg>

namespace NS {
    static inline void write(std::FILE* Stream, const char* const fmt, ...)
    {
		va_list args;
		va_start(args, fmt);
        std::vfprintf(Stream, fmt, args);
        std::clog << std::endl;
		va_end(args);
    }
}


#endif // !LOG_H_
