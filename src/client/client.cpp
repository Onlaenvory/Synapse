#include "client.hpp"
#include "../settings/setting.hpp"
#include "../features/notification/notifier.hpp"

#include "iostream"


void Client::start() {
  checkTerminal();
  Notifier::sent(LogLevel::Info, "Starting client...");
}

void Client::checkTerminal() {
  std::string input;

  Notifier::sent(LogLevel::Info, "Test Info");
  Notifier::sent(LogLevel::Debug, "Test Debug");
  Notifier::sent(LogLevel::Warning, "Test Warning");
  Notifier::sent(LogLevel::Critical, "Test Critical");

  printf("Is this display correctly [Y/n] : ");

  std::getline(std::cin, input);
  if (!input.empty() && input[0] == 'N' || input[0] == 'n') System::disableColoredFonts();

  printf(CLEAR_TERMINAL);
}
