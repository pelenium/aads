#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

struct Array {
  int num;
  int flag;
};

void Merge(vector<Array>& a, vector<Array> a1, vector<Array> a2) {
  int i1 = 0;
  int i2 = 0;
  while (i1 < (int)a1.size() || i2 < (int)a2.size()) {
    if (i1 < (int)a1.size() && i2 < (int)a2.size()) {
      if (a1[i1].num < a2[i2].num ||
          (a1[i1].num == a2[i2].num && a1[i1].flag > a2[i2].flag)) {
        a.push_back(a1[i1]);
        i1++;
      } else {
        a.push_back(a2[i2]);
        i2++;
      }
    } else if (i1 < (int)a1.size() && i2 >= (int)a2.size()) {
      a.push_back(a1[i1]);
      i1++;
    } else if (i1 >= (int)a1.size() && i2 < (int)a2.size()) {
      a.push_back(a2[i2]);
      i2++;
    }
  }
}

vector<Array> MergeSort(vector<Array> a) {
  if (a.size() <= 1) {
    return a;
  }
  int mid = a.size() / 2;
  vector<Array> l;
  vector<Array> r;
  for (int i = 0; i < (int)a.size(); i++) {
    if (i < mid) {
      l.push_back(a[i]);
    } else {
      r.push_back(a[i]);
    }
  }
  vector<Array> ans;
  l = MergeSort(l);
  r = MergeSort(r);
  Merge(ans, l, r);
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<Array> a;
  for (int i = 0; i < n; i++) {
    int l;
    int r;
    cin >> l >> r;
    a.push_back(Array{l, 1});
    a.push_back(Array{r, -1});
  }

  vector<Array> sorted_a = MergeSort(a);

  int num = 0;
  int cnt = 0;
  int last_l = sorted_a[0].num;
  vector<int> ans;
  for (auto i : sorted_a) {
    if (cnt == 0) {
      last_l = i.num;
    }

    cnt += i.flag;
    if (cnt == 0) {
      num++;
      ans.push_back(last_l);
      ans.push_back(i.num);
    }
  }
  cout << num << '\n';
  for (int i = 0; i < (int)ans.size(); i += 2) {
    cout << ans[i] << ' ' << ans[i + 1] << '\n';
  }
  cout << '\n';
}
