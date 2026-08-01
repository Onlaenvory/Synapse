#include "client.hpp"
#include "../settings/setting.hpp"
#include "../features/notification/notifier.hpp"
#include "../features/authenticate/auth.hpp"

#include "iostream"
#include <cstdio>
#include <string>
#include <string_view>


void Client::start() {
  std::string keys;
  checkTerminal();
  Logger::sent(LogLevel::Info, "Starting system...");
  Keys::getKeys();
  main();
}

void Client::checkTerminal() {
  std::string input;

  Logger::sent(LogLevel::Info, "Test Info");
  Logger::sent(LogLevel::Debug, "Test Debug");
  Logger::sent(LogLevel::Warning, "Test Warning");
  Logger::sent(LogLevel::Critical, "Test Critical");

  Logger::sent(LogLevel::Debug, "Is this display correctly [Y/n] : ");

  std::getline(std::cin, input);
  if (!input.empty() && input[0] == 'N' || input[0] == 'n') System::disableColoredFonts();

  printf(CLEAR_TERMINAL);
}

void Client::main() {
  std::string buffer;

  buffer += std::format("Welcome to project:re, {}", User::username);

  Logger::sent(LogLevel::Info, "Starting Client...");
  // Load gui, library, ect.
  Logger::sent(LogLevel::Info, "Loading Client...");
  printf("%s", buffer.data());
}
