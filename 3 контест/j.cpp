#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

struct Heap {
  vector<long long> elements;
  vector<int> ids;
  vector<int> pos;

  void Swap(int i, int j) {
    long long x = elements[i];
    elements[i] = elements[j];
    elements[j] = x;

    int tid = ids[i];
    ids[i] = ids[j];
    ids[j] = tid;

    pos[ids[i]] = i;
    pos[ids[j]] = j;
  }

  void SiftUp(int i) {
    while (i > 0) {
      int parent = (i - 1) / 2;

      if (elements[parent] <= elements[i]) {
        break;
      }

      Swap(parent, i);
      i = parent;
    }
  }

  void SiftDown(int i) {
    int n = (int)elements.size();

    while (2 * i + 1 < n) {
      int child = 2 * i + 1;

      if (child + 1 < n && elements[child + 1] < elements[child]) {
        child++;
      }

      if (elements[i] <= elements[child]) {
        break;
      }

      Swap(i, child);
      i = child;
    }
  }

  void Insert(long long x, int id) {
    elements.push_back(x);
    ids.push_back(id);
    pos[id] = (int)elements.size() - 1;
    SiftUp((int)elements.size() - 1);
  }

  long long GetMin() const { return elements[0]; }

  void ExtractMin() {
    int last = (int)elements.size() - 1;
    Swap(0, last);

    pos[ids[last]] = -1;

    elements.pop_back();
    ids.pop_back();

    if (!elements.empty()) {
      SiftDown(0);
    }
  }

  void DecreaseKey(int id, long long delta) {
    int i = pos[id];
    elements[i] -= delta;
    SiftUp(i);
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;

  Heap h;
  h.pos.resize(q + 1, -1);

  for (int i = 1; i <= q; i++) {
    string s;
    cin >> s;

    if (s == "insert") {
      long long x;
      cin >> x;
      h.Insert(x, i);
    } else if (s == "getMin") {
      cout << h.GetMin() << '\n';
    } else if (s == "extractMin") {
      h.ExtractMin();
    } else if (s == "decreaseKey") {
      int id;
      long long delta;
      cin >> id >> delta;
      h.DecreaseKey(id, delta);
    }
  }
}
