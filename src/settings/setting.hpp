#pragma once
#include <cstdint>
#include <string>
#include <string_view>

#define CLEAR_TERMINAL "\033[2J\033[H"

enum LogLevel : uint8_t
{
  Info = 0,
  Debug  = 1,
  Warning  = 2,
  Critical  = 3
};

namespace Setting
{
  inline bool enableStartUpMessage = true;
  inline bool enableLog = true;
  inline uint8_t logLevel = LogLevel::Critical;
};

namespace Fonts
{
  inline std::string_view clear = "\x1B[0m";
  inline std::string_view info = "\x1B[38;5;154m";
  inline std::string_view debug = "\x1B[38;5;226m";
  inline std::string_view warning = "\x1B[38;5;202m";
  inline std::string_view critical = "\x1B[38;5;196m";
}

class System
{
  public:
    static void disableColoredFonts() {
      Fonts::info = "";
      Fonts::debug = "";
      Fonts::warning = "";
      Fonts::critical = "";
    };
};

class User
{
  public:
    inline static std::string_view username = "Sally";
};
