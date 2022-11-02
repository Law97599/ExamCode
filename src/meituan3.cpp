#include <iostream>
#include <set>
#include <string>
#include <vector>

int n;
std::vector<std::vector<int>> map;
std::string s;
std::vector<int> visited;
std::vector<std::set<char>> setarr;

void dfs(int x) {
  std::set<char> curSet;
  curSet.insert(s[x - 1]);
  visited[x] = 1;

  for (int i = 1; i <= n; i++) {
    if (map[x][i] == 1) {
      if (visited[i] == 0) {
        dfs(i);
      }
      std::set<char> temp = setarr[i];
      curSet.insert(temp.begin(), temp.end());
    }
  }

  setarr[x] = curSet;
  return;
}

std::vector<int> solve() {
  std::vector<int> res(n + 1);
  dfs(1);
  for (int i = 1; i <= n; i++) {
    res[i] = setarr[i].size();
  }
  return res;
}

int main() {
  std::cin >> n;
  map = std::vector<std::vector<int>>(n + 1, std::vector<int>(n + 1, 0));
  visited = std::vector<int>(n + 1, 0);
  setarr = std::vector<std::set<char>>(n + 1, std::set<char>());
  for (int i = 2; i <= n; i++) {
    int p;
    std::cin >> p;
    map[p][i] = 1;
  }
  std::cin >> s;

  auto res = solve();
  for (int i = 1; i <= n; i++) {
    std::cout << res[i] << " ";
  }

  return 0;
}