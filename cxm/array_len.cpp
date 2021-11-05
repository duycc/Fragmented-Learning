/**
 * @file     array_len.cpp
 * @brief    C++数组长度是否可以为变量？
 * @author   DuYong
 * @date     2021-11-05
 */

#include <iostream>

void foo(int N) {
  int arr[N]; // N > 0
  std::cout << "N: " << N << std::endl;
  std::cout << "sizeof arr: " << sizeof(arr) << std::endl;
  arr[0] = 20;
  std::cout << "arr[0]: " << arr[0] << std::endl;
}

void goo() {
  int arr[10];
  arr[3] = 1;
  arr[20] = 3;
  std::cout << "sizeof arr: " << sizeof(arr) << std::endl;
  std::cout << "arr[3]: " << arr[3] << std::endl;
  std::cout << "arr[20]: " << arr[20] << std::endl;
}

void foo1() {
  int a;
  int b[4];
  int c;
  std::cout << "address foo1 a: " << &a << std::endl;
  std::cout << "address foo1 b: " << &b << std::endl;
  std::cout << "address foo1 c: " << &c << std::endl;
}

void foo2() {
  int a;
  int b[4];
  int c;
  std::cout << "address foo2 a: " << &a << std::endl;
  std::cout << "address foo2 b: " << &b << std::endl;
  std::cout << "address foo2 c: " << &c << std::endl;
  foo1();
}

void foo3() {
  int a;
  int b[4];
  int c;
  std::cout << "address foo3 a: " << &a << std::endl;
  std::cout << "address foo3 b: " << &b << std::endl;
  std::cout << "address foo3 c: " << &c << std::endl;
  foo2();
}

int main() {
  //   foo(6);
  // N: 6
  // sizeof arr: 24
  // arr[0]: 20

  //   goo();
  // sizeof arr: 40
  // arr[3]: 1
  // arr[20]: 3

  foo3();
  // address foo3 a: 0x7ffee5ed547c
  // address foo3 b: 0x7ffee5ed5480
  // address foo3 c: 0x7ffee5ed5478
  // address foo2 a: 0x7ffee5ed542c
  // address foo2 b: 0x7ffee5ed5430
  // address foo2 c: 0x7ffee5ed5428
  // address foo1 a: 0x7ffee5ed53dc
  // address foo1 b: 0x7ffee5ed53e0
  // address foo1 c: 0x7ffee5ed53d8

  return 0;
}
