#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define SPEC_CLASS_ENABLE
#include "OrangeEngine/Log.h"

#ifdef ORANGE_PLATFORM_WINDOWS
	#include <Windows.h>
#endif