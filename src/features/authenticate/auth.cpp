#include "auth.hpp"
#include "features/logger/logger.hpp"
#include "settings/setting.hpp"
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

void KeyManager::requestKey() {
  std::string inputKey;

  for (short attempt = 0; attempt < MAX_LOGIN_ATTEMPT; attempt++) {
    printf("Key : ");
    std::getline(std::cin, inputKey);

    Logger::sent(LogLevel::Info, "Verifying Key\t[-]");
    for (std::string_view validKey : activeKeys) if (inputKey == validKey) return;

    Logger::sent(LogLevel::Warning, "Invalid key\t[-]");
    printf("Invalid Key!!!\n");
  }

  Logger::sent(LogLevel::Critical, "Stopping session...");
  exit(0);
}

void KeyManager::loadKeys() {
  Logger::sent(LogLevel::Info, "Initializing Key\t[ 0% ]");

  if (KeyLists::Key.empty()) {
    Logger::sent(LogLevel::Critical, "Key set value is empty");
    return;
  }
  try {
    activeKeys.insert(activeKeys.end(), KeyLists::Key.begin(), KeyLists::Key.end());
    Logger::sent(LogLevel::Info, "Initializing Key\t[ COMPLETE ]");
  }
  catch (const std::bad_alloc& BA) {
    Logger::sent(LogLevel::Warning, std::format("Bad memory allocation << {}", BA.what()));
  }
};
