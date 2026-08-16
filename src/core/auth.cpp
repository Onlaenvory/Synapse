#include "logger.hpp"
#include "../data/active_keys.hpp"
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

const uint8_t MAX_LOGIN_ATTEMPT = 3;

namespace
{
  std::vector<std::string> activeKeys;
}

namespace KeyManager {
  void requestKey() {
    std::string inputKey;

    for (short attempt = 0; attempt < MAX_LOGIN_ATTEMPT; attempt++) {
      printf("Key : ");
      std::getline(std::cin, inputKey);

      Logger::log(LogLevel::Info, "Verifying Key\t[-]");
      for (std::string_view validKey : activeKeys) if (inputKey == validKey) return;

      Logger::log(LogLevel::Warning, "Invalid key\t[-]");
      printf("Invalid Key!!!\n");
    }

    Logger::log(LogLevel::Critical, "Stopping session...");
    exit(0);
  }

  void loadKeys() {
    Logger::log(LogLevel::Info, "Initializing Key\t[ 0% ]");

    if (KeyLists::Key.empty()) {
      Logger::log(LogLevel::Critical, "Key set value is empty");
      return;
    }
    try {
      activeKeys.insert(activeKeys.end(), KeyLists::Key.begin(), KeyLists::Key.end());
      Logger::log(LogLevel::Info, "Initializing Key\t[ COMPLETE ]");
    }
    catch (const std::bad_alloc& BA) {
      Logger::log(LogLevel::Warning, std::format("Bad memory allocation << {}", BA.what()));
    }
  };
};
