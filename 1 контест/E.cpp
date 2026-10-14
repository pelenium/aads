#include <iostream>
#include <vector>

using std::cin;
using std::cout;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  std::vector<long long> a;
  std::vector<long long> b;
  std::vector<long long> d;

  for (int i = 0; i < n; ++i) {
    long long ai;
    cin >> ai;
    a.push_back(ai);
  }
  for (int i = 0; i < n; ++i) {
    long long bi;
    cin >> bi;
    b.push_back(bi);
  }

  for (int i = 0; i < n; ++i) {
    d.push_back(a[i] - b[i]);
  }

  int q;
  cin >> q;

  while (q > 0) {
    long long x;
    cin >> x;

    long long target = -x;

    int l = 0;
    int r = n;
    while (l < r) {
      int mid = (r + l) / 2;
      if (d[mid] >= target) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    int p = l;

    int i1 = std::max(0, p - 1);
    int i2 = std::min(n - 1, p);

    long long v1 = std::max(a[i1] + x, b[i1]);
    long long v2 = std::max(a[i2] + x, b[i2]);

    int ans;
    if (v2 <= v1) {
      ans = i2;
    } else {
      ans = i1;
    }

    cout << ans + 1 << '\n';

    q--;
  }
}