#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;

long long solve() {
  long long res = 0;
  sort(arr.begin(), arr.end());
  vector<long long> dp(arr[n - 1] + 1, 0);
  dp[1] = 0;
  for (int i = 2; i < dp.size(); i++) {
    dp[i] = dp[i - 1] + 1;
    for (int j = 2; j <= sqrt(i); j++) {
      if (i % j == 0) {
        dp[i] = min(dp[i], dp[j] + dp[i / j] + 1);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    res += dp[arr[i]];
  }

  return res;
}

int main() {
  std::cin >> n;
  arr.resize(n);
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  std::cout << solve();

  return 0;
}