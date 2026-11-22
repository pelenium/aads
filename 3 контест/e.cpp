#include <deque>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::deque;
using std::string;

int main() {
  int n;
  cin >> n;

  deque<int> l;
  deque<int> r;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    if (s == "+") {
      int x;
      cin >> x;
      r.push_back(x);
    } else if (s == "*") {
      int x;
      cin >> x;
      l.push_back(x);
    } else if (s == "-") {
      cout << l.front() << '\n';
      l.pop_front();
    }

    if (l.size() < r.size()) {
      l.push_back(r.front());
      r.pop_front();
    } else if (l.size() > r.size() + 1) {
      r.push_front(l.back());
      l.pop_back();
    }
  }
}