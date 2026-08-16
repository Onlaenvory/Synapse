#pragma once

#include <string>
#include <variant>
#include <cstdint>
#include <unordered_map>

enum class LogLevel : uint8_t {
  Info,
  Debug,
  Warning,
  Critical
};

using supportedType = std::variant<bool, LogLevel>;

static std::unordered_map<std::string, supportedType> settings = {
  {"ColoredFont", true},
  {"ShowLog", true},
  {"LogLevel", LogLevel::Critical}
};

namespace Fonts {
  inline bool readConfig() {
    auto iterator = settings.find("ColoredFont");
    return (iterator != settings.end() && std::holds_alternative<bool>(iterator->second)) ? std::get<bool>(iterator->second) : false;
  }

  inline std::string_view clear() { return readConfig() ? "\x1B[0m" : ""; }
  inline std::string_view info() { return readConfig() ? "\x1B[38;5;154m" : ""; }
  inline std::string_view debug() { return readConfig() ? "\x1B[38;5;159m" : ""; }
  inline std::string_view warning() { return readConfig() ? "\x1B[38;5;226m" : ""; }
  inline std::string_view critical() { return readConfig() ? "\x1B[38;5;196m" : ""; }
};
