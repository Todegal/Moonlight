#pragma once

// Simple file for common preprocessor definitions

#define ML_ASSERT(x, ...) { if(!(x)) { ML_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define ML_CORE_ASSERT(x, ...) { if(!(x)) { ML_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define ML_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
#define BIT(x) 1 << x