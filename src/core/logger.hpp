#pragma once
#include "settings/setting.hpp"
#include <string_view>
#include <iostream>

namespace Logger
{
  inline void sent(LogLevel logLevel, std::string_view log) {
    std::string buffers;

    if (logLevel > System::getLogLevel()) return;

    switch (logLevel) {
      case LogLevel::Info:
        buffers =  std::format("[ {}INFO{} ] : {}\n", Fonts::info(), Fonts::clear(), log);
        break;
      case LogLevel::Warning:
        buffers = std::format("[ {}WARNING{} ] : {}\n", Fonts::warning(), Fonts::clear(), log);
        break;
      case LogLevel::Critical:
        buffers = std::format("[ {}CRITICAL{} ] : {}\n", Fonts::critical(), Fonts::clear(), log);
        break;
      default:
        buffers = std::format("[ UNDEFINE ] : {}\n", log);
        break;
    }

    printf("%s", buffers.data());
  }

  inline void checkTerminal() {
    std::string input;

    Logger::sent(LogLevel::Info, "Test Info");
    Logger::sent(LogLevel::Warning, "Test Warning");
    Logger::sent(LogLevel::Critical, "Test Critical");

    printf("Is this display correctly [Y/n] : ");

    if (std::cin.peek() == ' ') std::cin.ignore();
    std::getline(std::cin, input);

    printf(CLEAR_TERMINAL);
    if (!input.empty() && (input[0] == 'N' || input[0] == 'n')) {
      System::disableColoredFonts();
      Logger::sent(LogLevel::Info, "Colored fonts\t[ DISABLE ]");
    }
  }
};
