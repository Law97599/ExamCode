#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> G;
long long res;

void dfs(int u, long long add) {
  long long count = u - 1 - add;
  res += count;
  for (int i = 0; i < G[u].size(); i++) {
    dfs(G[u][i], add + count);
  }
  return;
}

int main() {
  cin >> n;
  G = vector<vector<int>>(n + 1, vector<int>());
  res = 0;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (x > y) res = -1;
    G[x].push_back(y);
  }
  dfs(1, 0ll);
  if (res == -1) {
    cout << -1 << endl;
    return 0;
  }
  cout << res << endl;
  return 0;
}