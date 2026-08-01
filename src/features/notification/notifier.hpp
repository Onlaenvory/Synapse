#pragma once
#include "settings/setting.hpp"

#include <string_view>

class Logger
{
  public:
    static void sent(LogLevel logLevel, std::string_view log);
};
