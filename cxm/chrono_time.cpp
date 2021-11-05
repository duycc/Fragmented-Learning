/**
 * @file     chrono_time.cpp
 * @brief
 * @author   DuYong
 * @date     2021-11-05
 */

#include <chrono>
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
#include <thread>

using namespace std::chrono;

void foo() {
  //   time_point<high_resolution_clock> begin = high_resolution_clock::now();
  //   std::this_thread::sleep_for(milliseconds(20));
  //   auto end = high_resolution_clock::now();
  //   std::cout << "time: " << duration_cast<milliseconds>(end - begin).count() << std::endl;

  // duration 时间段
  //   auto sec = seconds(10);
  //   auto mill = duration_cast<milliseconds>(sec);
  //   std::cout << sec.count() << std::endl;
  //   std::cout << mill.count() << std::endl;

  // time_point 时间点
  //   time_point<system_clock, milliseconds> tp(seconds(12));
  //   std::cout << tp.time_since_epoch().count() << std::endl;
  //   std::time_t t = system_clock::to_time_t(tp);
  //   std::cout << "time: " << ctime(&t) << std::endl;

  // clock 时钟

  // C语言时钟
  //   clock_t start = clock();
  //   std::cout << start << " 个时钟\n";
  //   for (int i = 0; i < 100000000; ++i) {
  //   }
  //   clock_t end = clock();
  //   std::cout << end << " 个时钟\n";
  //   std::cout << "循环秒数: " << (double)(end - start) / CLOCKS_PER_SEC << std::endl;

  struct timeval time;
  gettimeofday(&time, NULL);
  std::cout << time.tv_sec << "s\n";
}

int main() {
  foo();
  return 0;
}
