#include <cstdint>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

const int c64 = 64;
const int c8 = 8;
const int c256 = 256;
const int c255 = 255;

int main() {
  int n;
  cin >> n;

  vector<uint64_t> a(n);
  vector<uint64_t> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int s = 0; s < c64; s += c8) {
    vector<int> cnt(c256, 0);

    for (int i = 0; i < n; ++i) {
      int d = (a[i] >> s) & c255;
      cnt[d]++;
    }

    for (int i = 1; i < c256; ++i) {
      cnt[i] += cnt[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
      int d = (a[i] >> s) & c255;
      b[--cnt[d]] = a[i];
    }

    a.swap(b);
  }

  for (int i = 0; i < n; ++i) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}
