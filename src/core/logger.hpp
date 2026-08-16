#pragma once

#include "setting.hpp"
#include <format>
#include <string_view>
#include <variant>

class Logger
{
  private:
    static LogLevel getConfigLevel() {
      auto iterator = settings.find("LogLevel");
      if (iterator != settings.end() && std::holds_alternative<LogLevel>(iterator->second)) return std::get<LogLevel>(iterator->second);

      return LogLevel::Info;
    }

    static bool isEnable() {
      auto iterator = settings.find("ShowLog");
      if (iterator != settings.end() && std::holds_alternative<bool>(iterator->second)) return std::get<bool>(iterator->second);

      return true;
    }

  public:
    inline static void log(LogLevel level, std::string_view message) {
      if (level > getConfigLevel() || !isEnable()) return;

      std::string buffer;

      switch (level) {
        case LogLevel::Info :
          buffer = std::format("[ {}INFO{} ] : {}", Fonts::info(), Fonts::clear(), message);
          break;
        case LogLevel::Debug :
          buffer = std::format("[ {}DEBUG{} ] : {}", Fonts::debug(), Fonts::clear(), message);
          break;
        case LogLevel::Warning :
          buffer = std::format("[ {}WARNING{} ] : {}", Fonts::warning(), Fonts::clear(), message);
          break;
        case LogLevel::Critical :
          buffer = std::format("[ {}CRITICAL{} ] : {}", Fonts::critical(), Fonts::clear(), message);
          break;
      }

      printf("%s", buffer.c_str());
    }
};
