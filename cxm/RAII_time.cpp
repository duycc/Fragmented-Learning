/**
 * @file     RAII_time.cpp
 * @brief
 * @author   DuYong
 * @date     2021-11-05
 */

#include <chrono>
#include <ctime>
#include <iostream>
#include <sys/time.h>
#include <thread>

using namespace std::chrono;

class TimerLog {
public:
  TimerLog(const std::string &tag) {
    m_begin = high_resolution_clock::now();
    m_tag = tag;
  }

  void reset() { m_begin = high_resolution_clock::now(); }

  long long elapsed() {
    return static_cast<long long>(duration_cast<milliseconds>(high_resolution_clock::now() - m_begin).count());
  }

  static time_point<high_resolution_clock> now() { return high_resolution_clock::now(); }

  static long long diffUs(time_point<high_resolution_clock> before, time_point<high_resolution_clock> after) {
    return static_cast<long long>(duration_cast<microseconds>(after - before).count());
  }

  static long long diffMs(time_point<high_resolution_clock> before, time_point<high_resolution_clock> after) {
    return static_cast<long long>(duration_cast<milliseconds>(after - before).count());
  }

  static long long getCurrentMs() {
    struct timeval time;
    gettimeofday(&time, NULL);
    return static_cast<long long>(time.tv_sec * 1000) + static_cast<long long>(time.tv_usec / 1000);
  }

  static void showCurrTime() {
    time_t now = time(0);
    char *dt = ctime(&now);
    std::cout << "curr time is: " << dt << std::endl;
    std::cout << "curr ms is: " << getCurrentMs() << std::endl;
  }

  static struct timeval getCurrentTimeOfDay() {
    struct timeval time;
    gettimeofday(&time, NULL);
    return time;
  }

  ~TimerLog() {
    auto time = duration_cast<milliseconds>(high_resolution_clock::now() - m_begin).count();
    std::cout << "time { " << m_tag << " } " << static_cast<double>(time) << " ms" << std::endl;
  }

private:
  time_point<high_resolution_clock> m_begin;
  std::string m_tag;
};

#define CAL_SCOPE_TIME(x) TimerLog tl(x)
#define CAL_TIME_BEGIN(x) auto begin_##x = TimerLog::now();
#define CAL_TIME_END(x)                                                                                                \
  std::cout << "time { " << #x << " } " << TimerLog::diffMs(begin_##x, TimerLog::now()) << "ms" << std::endl;

void testTimerLog() {
  auto func = [] {
    for (int i = 0; i < 5; ++i) {
      std::cout << "i: " << i << std::endl;
      std::this_thread::sleep_for(milliseconds(1));
    }
  };
  {
    // TimerLog tl("func");
    CAL_SCOPE_TIME("func time");
    func();
  }
}

int main() {
  testTimerLog();

  return 0;
}
