#pragma once

#include <vector>
#include <string>


class Keys
{
  private:
    static std::vector<std::string> activeKeys;
  public:
    static void checkKey();
    static void getKeys();
    static void loadKeys();
};
