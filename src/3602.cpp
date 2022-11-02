#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
long long n, q;
long long l, r, cnt = 0;
vector<vector<long long>> a;

long long solve() {
  if (a.empty()) {
    a.push_back({l, r});
    cnt += r - l + 1;
    return n - cnt;
  }
  sort(a.begin(), a.end(),
       [](vector<long long> a, vector<long long> b) { return a[0] < b[0]; });
  int i = 0;
  while (i < a.size()) {
    if (l > a[i][1]) continue;
    if (r < a[i][0]) break;

    int cl = max(l, a[i][0]);
    int cr = min(r, a[i][1]);
    cnt -= cr - cl + 1;

    int l1, r1, l2, r2;
    if (cl == l) {
      l1 = a[i][0];
      r1 = l - 1;
    } else {
      l1 = l;
      r1 = a[i][0] - 1;
    }
    if (cr == r) {
      l2 = r + 1;
      r2 = a[i][1];
    } else {
      l2 = a[i][1] + 1;
      r2 = r;
    }

    a[i][0] = l1;
    a[i][1] = r1;
    l = l2;
    r = r2;

    i++;
  }
  if (l <= r) {
    a.push_back({l, r});
    cnt += (r - l + 1);
  }
  return n - cnt;
}

int main() {
  cin >> n >> q;
  for (int i = 0; i < q; i++) {
    cin >> l >> r;
    cout << solve() << endl;
  }
  return 0;
}