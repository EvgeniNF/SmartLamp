#pragma once

#include "logs.hpp"

#define ASSERT_NULL(ptr) \
    if (not ptr) { \
        LOG_ERROR("assert: " << #ptr << " is null!"); \
        delay(1000); \
        ESP.restart(); \
    }       

#define ASSERT_EQ(val1, val2) \
    if (val1 != val2) { \
        LOG_ERROR("assert: " << #val1 << " != " << #val2); \
        delay(1000); \
        ESP.restart(); \
    }

#define ASSERT_NQ(val1, val2) \
    if (val1 == val2) { \
        LOG_ERROR("assert: " << #val1 << " == " << #val2); \
        delay(1000); \
        ESP.restart(); \
    }

#define ASSERT_TRUE(val1) \
    if (val1 != true) { \
        LOG_ERROR("assert: " << #val1 << " != " << std::boolalpha << true); \
        delay(1000); \
        ESP.restart(); \
    }

#define ASSERT_FALSE(val1) \
    if (val1 != false) { \
        LOG_ERROR("assert: " << #val1 << " != " << std::boolalpha << false); \
        delay(1000); \
        ESP.restart(); \
    }

#define ASSERT_NLESS(val1, val2) \
    if (val1 > val2) { \
        LOG_ERROR("assert: " << #val1 << " > " << #val2); \
        delay(1000); \
        ESP.restart(); \
    }
    