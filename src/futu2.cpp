#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> w, v;

int solve() {
  vector<int> dp(m + 1, 0);

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j < n; j++) {
      if (i - w[j] >= 0) {
        dp[i] = max(dp[i], dp[i - w[j]] + v[j]);
      }
    }
  }

  return dp[m];
}

int main() {
  cin >> n >> m;
  w.resize(n);
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> v[i];
  }
  cout << solve() << endl;
  return 0;
}