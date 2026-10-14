#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;

const int cMagicNumber = 8;

int main() {
  cout << std::fixed;

  int n;
  cin >> n;

  std::vector<long double> a;
  for (int i = 0; i < n; i++) {
    long double ai;
    cin >> ai;
    a.push_back(ai);
  }

  std::vector<long double> pref_log = {0};
  long double current = 0;

  for (int i = 0; i < n; i++) {
    current += std::log(a[i]);
    pref_log.push_back(current);
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    int l;
    int r;
    cin >> l >> r;

    long double pref_l = pref_log[l];
    long double pref_r = pref_log[r + 1];

    long double answer = std::exp((pref_r - pref_l) / (r - l + 1));

    cout << std::setprecision(cMagicNumber) << answer << "\n";
  }

  return 0;
}