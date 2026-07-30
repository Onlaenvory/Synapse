#pragma once
#include <string>
#include "settings/setting.hpp"

class Notifier
{
  public:
    static void sent(LogLevel logLevel, std::string_view log);
};
