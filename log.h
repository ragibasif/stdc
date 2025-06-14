/*
 * File: log.h
 * Author: Ragib Asif
 * Email: ragib.asif30@myhunter.cuny.edu
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 *
 * Minimal logging library.
 *
 */

#ifndef __LOG_H__
#define __LOG_H__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "aec.h"
#include "common.h"

// TODO: allow logging to be redirected to file
// TODO: allow more convenient option to toggle colors

enum log_types {
    INFO = 0,
    DEBUG = 1,
    TRACE = 2,
    WARN = 3,
    ERROR = 4,
    FATAL = 5
};

static const char *log_literal(enum log_types type) {
    switch (type) {
    case (INFO): {
        return "INFO\0";
    }
    case (DEBUG): {
        return "DEBUG\0";
    }
    case (TRACE): {
        return "TRACE\0";
    }
    case (WARN): {
        return "WARN\0";
    }
    case (ERROR): {
        return "ERROR\0";
    }
    case (FATAL): {
        return "FATAL\0";
    }
    default:
        return "INFO\0";
    }
}

static const char *get_log_literal_color(enum log_types type) {
    switch (type) {
    case (INFO): {
        return AEC_GREEN;
    }
    case (DEBUG): {
        return AEC_MAGENTA;
    }
    case (TRACE): {
        return AEC_CYAN;
    }
    case (WARN): {
        return AEC_YELLOW;
    }
    case (ERROR): {
        return AEC_RED;
    }
    case (FATAL): {
        return AEC_BLUE;
    }
    default:
        return AEC_DEFAULT;
    }
}

static void log_output(const char *file, unsigned int line,
                       const char *function, enum log_types type,
                       const char *format, ...);

static const char *get_current_time(void) {
    time_t now;
    char *time_str;
    now = time(NULL);
    time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0';
    return time_str;
}

#define INFO(format, ...)                                                      \
    log_output(__FILE__, __LINE__, __func__, INFO, format, ##__VA_ARGS__)
#define DEBUG(format, ...)                                                     \
    log_output(__FILE__, __LINE__, __func__, DEBUG, format, ##__VA_ARGS__)
#define TRACE(format, ...)                                                     \
    log_output(__FILE__, __LINE__, __func__, TRACE, format, ##__VA_ARGS__)
#define WARN(format, ...)                                                      \
    log_output(__FILE__, __LINE__, __func__, WARN, format, ##__VA_ARGS__)
#define ERROR(format, ...)                                                     \
    log_output(__FILE__, __LINE__, __func__, ERROR, format, ##__VA_ARGS__)
#define FATAL(format, ...)                                                     \
    log_output(__FILE__, __LINE__, __func__, FATAL, format, ##__VA_ARGS__)

static void log_output(const char *file, unsigned int line,
                       const char *function, enum log_types type,
                       const char *format, ...) {

    const char *literal = log_literal(type);
    const char *literal_color = get_log_literal_color(type);
    const char *current_time = get_current_time();

#ifdef LOG_COLOR
    fprintf(stderr, "%s%s [%s:%d %s()]%s ", AEC_DIM, current_time, file, line,
            function, AEC_RESET);
    fprintf(stderr, "%s%s%s%s%s ", AEC_DEFAULT, AEC_BOLD, literal_color,
            literal, AEC_RESET);
#else
    fprintf(stderr, "%s [%s:%d %s()] ", current_time, file, line, function);
    fprintf(stderr, "%s ", literal);
#endif

    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);

    fprintf(stderr, "\n");
}

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __LOG_H__
