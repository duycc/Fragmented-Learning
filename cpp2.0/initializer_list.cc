/**
 * @file     initializer_list.cc
 * @brief
 * @author   YongDu
 * @date     2022-03-29
 */

#include <initializer_list>
#include <iostream>

void print(std::initializer_list<int> vals) {
  for (auto it = vals.begin(); it != vals.end(); ++it) {
    std::cout << *it << std::endl;
  }
}

int main() {
  std::cout << "hello world..." << std::endl;
  print({1, 3, 4, 5, 6});
  return 0;
}