#include <iostream>
#include <random>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

const int c123 = 123;
const int c45 = 45;
const int c1e7 = 1e7;
const int c4321 = 4321;

vector<vector<int>> Partition(vector<int>& a, int pivot) {
  vector<int> a1;
  vector<int> a2;
  vector<int> a3;

  for (int i = 0; i < (int)a.size(); i++) {
    if (a[i] < pivot) {
      a1.push_back(a[i]);
    }
    if (a[i] == pivot) {
      a2.push_back(a[i]);
    }
    if (a[i] > pivot) {
      a3.push_back(a[i]);
    }
  }

  return vector<vector<int>>{a1, a2, a3};
}

int QuickSelect(vector<int>& a, int k) {
  int n = a.size();
  if (n == 1) {
    return a[0];
  }
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distrib(0, n - 1);
  int pivot = distrib(gen);
  vector<vector<int>> splitted = Partition(a, a[pivot]);

  int a1_size = (int)splitted[0].size();
  int a2_size = (int)splitted[1].size();

  if (k <= a1_size) {
    return QuickSelect(splitted[0], k);
  }
  if (a1_size < k && k <= a1_size + a2_size) {
    return a[pivot];
  }

  return QuickSelect(splitted[2], k - (a1_size + a2_size));
}

int main() {
  int n;
  int k;
  int a0;
  int a1;
  cin >> n >> k >> a0 >> a1;
  vector<int> a;
  a.push_back(a0);
  a.push_back(a1);
  for (int i = 2; i < n; i++) {
    int ai = (a[i - 1] * c123 + a[i - 2] * c45) % (c1e7 + c4321);
    a.push_back(ai);
  }
  int res = QuickSelect(a, k);
  cout << res;
  cout << '\n';
}