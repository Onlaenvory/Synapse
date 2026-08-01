#include "auth.hpp"
#include "features/notification/notifier.hpp"
#include "settings/setting.hpp"

#include <cstdio>
#include <iostream>

void Keys::getKeys() {
  std::string key;
  int max_attempt = 3;

  Logger::sent(LogLevel::Info, "Getting user key...");
  for (int attempt = max_attempt - 1; attempt >= 0; attempt--) {
    printf("Key : ");
    std::getline(std::cin, key);

    Logger::sent(LogLevel::Info, "Verifing key...");
    for (std::string_view Keys : Keys::ActiveKeys) {
      if (key == Keys) {
        printf("Login with key : %s\n", key.data());
        return;
      }
    }

    printf("Invalid Key!!!, Please try again\tremaining attempt[%d]\n", attempt);
    Logger::sent(LogLevel::Warning, "Invalid key...");
  }
  Logger::sent(LogLevel::Critical, "Stopping session...");
  exit(0);
}
