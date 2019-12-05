#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <Windows.h>

#define ML_API __declspec(dllexport)

#define ML_ASSERT(x, ...) { if(!(x)) { ML_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define ML_CORE_ASSERT(x, ...) { if(!(x)) { ML_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }

#include "Core/Log.h"
