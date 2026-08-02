#include "client.hpp"
#include "../settings/setting.hpp"
#include "../features/logger/logger.hpp"
#include "../features/authenticate/auth.hpp"
#include <string>
#include <format>


void Client::start() {
  Logger::checkTerminal();
  KeyManager::loadKeys();
  KeyManager::requestKey();
  Client::main();
}

void Client::main() {
  std::string buffer;
  buffer = std::format("Welcome to project:re, {}\nMenu", User::username);

  Logger::sent(LogLevel::Info, "Starting Client...");
  Logger::sent(LogLevel::Info, "Loading Client...");
  printf("%s", buffer.data());
}
