#pragma once
#include "settings/setting.hpp"
#include <string_view>

namespace Logger
{
  void sent(LogLevel logLevel, std::string_view log);
  void checkTerminal();
};
