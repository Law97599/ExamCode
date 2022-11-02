#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

// vector<vector<int>> map;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, x, y;

// int bfs(int x, int y) {
//     int res = 0;
//     queue<vector<int>> q;
//     q.push({x, y});
//     while (!q.empty()) {
//         int cur = q.size();
//         res = max(res, cur);
//         for (int k = 0; k < cur; k++){
//             auto item = q.front();
//             q.pop();
//             auto cx = item[0], cy = item[1];
//             for (int i = 0; i < 4; i++) {
//                 if (cx + dx[i] <= 0 || cx + dx[i] > n || cy + dy[i] <= 0 || cy + dy[i] > m) {
//                     continue;
//                 }
//                 if (map[cx + dx[i]][cy + dy[i]] == 0) {
//                     map[cx + dx[i]][cy + dy[i]] = 1;
//                     q.push({cx + dx[i], cy + dy[i]});
//                 }
//             }
//         }
//     }
//     return res;
// }

int dp(int x, int y) {
  vector<vector<int>> dp =
      vector<vector<int>>(n + 1, vector<int>(m + 1, INT_MAX));
  dp[x][y] = 0;
  map<int, int> count;
  for (int i = x - 1; i > 0; i--) {
    dp[i][y] = dp[i + 1][y] + 1;
    count[dp[i][y]]++;
  }
  for (int i = x + 1; i <= n; i++) {
    dp[i][y] = dp[i - 1][y] + 1;
    count[dp[i][y]]++;
  }
  for (int i = y - 1; i > 0; i--) {
    dp[x][i] = dp[x][i + 1] + 1;
    count[dp[x][i]]++;
  }
  for (int i = y + 1; i <= m; i++) {
    dp[x][i] = dp[x][i - 1] + 1;
    count[dp[x][i]]++;
  }

  for (int i = x - 1; i > 0; i--) {
    for (int j = y - 1; j > 0; j--) {
      dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + 1;
      count[dp[i][j]]++;
    }
  }
  for (int i = x - 1; i > 0; i--) {
    for (int j = y + 1; j <= m; j++) {
      dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
      count[dp[i][j]]++;
    }
  }
  for (int i = x + 1; i <= n; i++) {
    for (int j = y - 1; j > 0; j--) {
      dp[i][j] = min(dp[i - 1][j], dp[i][j + 1]) + 1;
      count[dp[i][j]]++;
    }
  }
  for (int i = x + 1; i <= n; i++) {
    for (int j = y + 1; j <= m; j++) {
      dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
      count[dp[i][j]]++;
    }
  }
  int res = -1;
  for (auto item : count) {
    res = max(item.second, res);
  }
  return res;
}

int main() {
  cin >> n >> m >> x >> y;
  if (n == 1 && m == 1) {
    cout << 0 << endl;
    return 0;
  }
  // map = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
  // map[x][y] = 1;
  // cout << bfs(x, y) << endl;
  cout << dp(x, y) << endl;

  return 0;
}