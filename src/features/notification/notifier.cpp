#include "notifier.hpp"
#include "../../settings/setting.hpp"

#include <cstdio>
#include <format>
#include <string_view>

void Logger::sent(LogLevel logLevel, std::string_view log) {
  std::string buffers;

  if (!Setting::enableLog) return;

  if (logLevel <= Setting::logLevel) {
    switch (logLevel) {
      case LogLevel::Info: buffers +=  std::format("[ {}INFO{} ] : ", Fonts::info, Fonts::clear); break;
      case LogLevel::Debug: buffers += std::format("[ {}DEBUG{} ] : ", Fonts::debug, Fonts::clear); break;
      case LogLevel::Warning: buffers += std::format("[ {}WARNING{} ] : ", Fonts::warning, Fonts::clear); break;
      case LogLevel::Critical: buffers += std::format("[ {}CRITICAL{} ] : ", Fonts::critical, Fonts::clear); break;
      default: buffers += std::format("[ UNDEFINE ] : "); break;
    }

    buffers += log;

    printf("%s\n", buffers.data());
  }
}
