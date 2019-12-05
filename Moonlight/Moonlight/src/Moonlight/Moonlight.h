#pragma once

#define ML_API __declspec(dllimport)

#define ML_ASSERT(x, ...) { if(!(x)) { ML_CRITICAL("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define ML_CORE_ASSERT(x, ...) { if(!(x)) { ML_CORE_CRITICAL("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }

#include "Moonlight/Core/Log.h"
#include "Moonlight/Core/Application.h"