#pragma once

#include "../core/logger.hpp"
#include "../features/authenticate/auth.hpp"
#include "../features/display/display.hpp"

class Client
{
  public:
    Client() {
      Logger::checkTerminal();
      KeyManager::loadKeys();
    };
    ~Client() {
      Logger::sent(LogLevel::Info, "Exiting\t\t[ COMPLETE ]");
    };

    void run() {
      KeyManager::requestKey();
      DisplayManager::showMenu();
    }
};
