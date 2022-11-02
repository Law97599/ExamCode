#include <iostream>
#include <vector>

int n, m, k;
std::vector<long long> a, b, c;

int solve() {
  std::vector<std::vector<long long>> dp(m + 1, std::vector<long long>(4));
  dp[0][0] = 0;
  dp[0][1] = k;
  dp[0][2] = 0;
  dp[0][3] = k;
  for (int i = 1; i <= m; i++) {
    long long pre0 = dp[i - 1][0] + (dp[i - 1][1] == c[i] ? a[i] : b[i]);
    long long pre1 = dp[i - 1][2] + (dp[i - 1][3] == c[i] ? a[i] : b[i]);
    if (pre0 > pre1) {
      dp[i][0] = pre0;
      dp[i][1] = c[i];
    } else {
      dp[i][0] = pre1;
      dp[i][1] = c[i];
    }

    if (dp[i - 1][0] > dp[i - 1][2]) {
      dp[i][2] = dp[i - 1][0];
      dp[i][3] = dp[i - 1][1];
    } else {
      dp[i][2] = dp[i - 1][2];
      dp[i][3] = dp[i - 1][3];
    }
  }

  return dp[m][0];
}

int main() {
  std::cin >> n >> m >> k;
  a.resize(m + 1);
  b.resize(m + 1);
  c.resize(m + 1);
  for (int i = 1; i <= m; i++) {
    std::cin >> c[i];
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i];
  }

  std::cout << solve() << std::endl;

  return 0;
}