#pragma once

#include <vector>
#include <string_view>

class Keys
{
  public:
    static inline const std::vector<std::string_view> ActiveKeys = {"K1-E9-I7-F2","123"};
    static void getKeys();
};
