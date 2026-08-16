#include "core/logger.hpp"

int main() {
  Logger::log(LogLevel::Critical, "ようこそ!");
  return 0;
}
