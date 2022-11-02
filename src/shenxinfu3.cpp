#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int n, x;
vector<int> arr;

int solve() {
  int res = 0;
  int i = 0, mmin = INT_MAX, mmax = INT_MIN;
  while (i < n) {
    mmin = min(arr[i], mmin);
    mmax = max(arr[i], mmax);
    if ((mmax - mmin) > x * 2) {
      res++;
      mmin = arr[i];
      mmax = arr[i];
    }
    i++;
  }
  return res;
}

int main() {
  cin >> n >> x;
  arr.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << solve();

  return 0;
}