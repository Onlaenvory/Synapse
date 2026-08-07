#pragma once

#include <cstdio>
#include <string>
#include <format>

namespace DisplayManager
{
  inline void showMenu() {
    std::string buffer;

    buffer = std::format("Menu");
    printf("%s\n", buffer.data());
  };
}
