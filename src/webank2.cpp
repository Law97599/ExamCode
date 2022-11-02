#include <iostream>

using namespace std;

int solve(long long a, long long b) {
  if (a == b) return 0;
  int res = 0;
  while (((a & 0x01) != 1) && a != b) {
    a >>= 1;
    res++;
  }
  if (a == b) {
    int ans = 0;
    ans += res / 3;
    ans += res % 3;
    return ans;
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    long long a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);
    cout << solve(a, b) << endl;
  }
  return 0;
}