/**
 * @file     io.cc
 * @brief
 * @author   YongDu
 * @date     2022-04-13
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void testIOStream() {
  int i = -1;
  cin >> i;
  cout << i << endl;
}

void testFStream() {
  fstream in("test.txt");
  if (!in) {
    cout << "Error" << endl;
    return;
  }
  string line;
  while (getline(in, line)) {
    cout << line << endl;
  }
}

void testStringStream() {
  // fstream in("test.txt");
  // if (!in) {
  //   cout << "Open File Error." << endl;
  //   return;
  // }

  // string line;
  // string passwd;
  // while (getline(in, line)) {
  //   istringstream ss(line);
  //   int i = 0;
  //   while (ss >> passwd) {
  //     cout << passwd + (1 == ++i ? "" : "x") << " ";
  //   }
  //   cout << endl;
  // }

  // int a = -1;
  // string s = "101";
  // istringstream is(s);
  // cout << is.str() << endl;

  // is >> a;
  // cout << a << endl;

  string str;
  ostringstream os(str);
  // os << "hello";
  str = "hello";
  cout << os.str() << endl;
}

int main() {
  // testIOStream();
  // testFStream();
  testStringStream();
  return 0;
}