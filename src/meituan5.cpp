#include <algorithm>
#include <iostream>
#include <vector>

int n;
std::vector<int> a, b, c;

long long solve() {
  long long res = 0;
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  std::sort(c.begin(), c.end());

  std::vector<long long> temp(n, 0);

  int l = 0;
  for (int i = 0; i < n; i++) {
    while (l < n && b[i] >= c[l]) l++;
    int r = l;
    while (r < n && b[i] * 2 >= c[r]) r++;
    temp[i] = r - l;
  }

  l = 0;
  for (int i = 0; i < n; i++) {
    while (l < n && a[i] >= b[l]) l++;
    int r = l;
    while (r < n && a[i] * 2 >= b[r]) {
      res += temp[r];
      r++;
    }
  }

  return res;
}

int main() {
  std::cin >> n;
  a.resize(n);
  b.resize(n);
  c.resize(n);

  for (int i = 0; i < n; i++) std::cin >> a[i];
  for (int i = 0; i < n; i++) std::cin >> b[i];
  for (int i = 0; i < n; i++) std::cin >> c[i];

  std::cout << solve();

  return 0;
}