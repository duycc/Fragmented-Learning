/**
 * @file     scope_exit.cpp
 * @brief
 * @author   DuYong
 * @date     2021-11-05
 */

#include <fstream>
#include <functional>
#include <iostream>

class ScopeExit {
public:
  ScopeExit() = default;

  ScopeExit(const ScopeExit &) = delete;
  ScopeExit &operator=(const ScopeExit &) = delete;

  ScopeExit(ScopeExit &&) = default;
  ScopeExit &operator=(ScopeExit &&) = default;

  template <typename Fn, typename... Args>
  ScopeExit(Fn &&fn, Args &&...args) {
    func_ = std::bind(std::forward<Fn>(fn), std::forward<Args>(args)...);
  }

  ~ScopeExit() {
    if (func_) {
      func_();
    }
  }

private:
  std::function<void()> func_;
};

#define _CONCAT(a, b) a##b
#define _MAKE_SCOPE_(line) ScopeExit _CONCAT(defer, line) = [&]()

#undef SCOPE_GUARD
#define SCOPE_GUARD _MAKE_SCOPE_(__LINE__)

void test() {
  bool flg;
  char *str = new char[100];
  std::ofstream os("test.txt");

  SCOPE_GUARD {
    delete[] str;
    os.close();
  };

  if (flg) {
    // ...
    return;
  }
  if (flg) {
    // ...
    return;
  }
  // ...
}

int main() {
  test();
  return 0;
}
