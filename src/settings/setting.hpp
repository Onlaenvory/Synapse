#pragma once
#include <cstdint>
#include <string_view>

#define CLEAR_TERMINAL "\033[2J\033[H"

enum LogLevel : uint8_t
{
  Info = 0,
  Warning  = 1,
  Critical  = 2
};

namespace Setting
{
  inline bool enableStartUpMessage = true;
  inline bool enableLog = true;
};

namespace Fonts
{
  inline bool enableColoredFonts = true;

  inline std::string_view clear() { return enableColoredFonts ? "\x1B[0m" : ""; }
  inline std::string_view info() { return enableColoredFonts ? "\x1B[38;5;154m" : ""; }
  inline std::string_view warning() { return enableColoredFonts ? "\x1B[38;5;226m" : ""; }
  inline std::string_view critical() { return enableColoredFonts ? "\x1B[38;5;196m" : ""; }
}

class System
{
  public:
    static void disableColoredFonts() { Fonts::enableColoredFonts = false; }
    static inline uint8_t setLogLevel = LogLevel::Critical;
};

class User
{
  public:
    inline static std::string_view username = "User";
};
