#include <iostream>
#include <vector>

using namespace std;

int main() {
  int m = 7, n = 3;

  vector<int> dp(m, 0);
  dp[0] = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j++) {
      dp[j] = dp[j - 1] + dp[j];
    }
  }

  cout << dp[m - 1];

  return 0;
}