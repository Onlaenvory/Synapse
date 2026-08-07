#pragma once
#include <cstdint>
#include <atomic>
#include <string_view>

#define CLEAR_TERMINAL "\033[2J\033[H"

enum LogLevel : uint8_t
{
  Info = 0,
  Warning  = 1,
  Critical  = 2
};

namespace Fonts
{
  inline std::atomic<bool> enableColoredFonts {true};

  inline std::string_view clear() { return enableColoredFonts.load() ? "\x1B[0m" : ""; }
  inline std::string_view info() { return enableColoredFonts.load() ? "\x1B[38;5;154m" : ""; }
  inline std::string_view warning() { return enableColoredFonts.load() ? "\x1B[38;5;226m" : ""; }
  inline std::string_view critical() { return enableColoredFonts.load() ? "\x1B[38;5;196m" : ""; }
}

class System
{
  private:
    static inline LogLevel currentLogLevel = LogLevel::Critical;

  public:
    static void disableColoredFonts() { Fonts::enableColoredFonts.store(false); }
    static void enableColoredFonts() { Fonts::enableColoredFonts.store(true); }

  public:
    static void setLogLevel(LogLevel level) { currentLogLevel = level; }
    static LogLevel getLogLevel() { return currentLogLevel; }
};
