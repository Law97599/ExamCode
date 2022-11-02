// #include <iostream>
// #include <unordered_set>
// #include <vector>
// #include <climits>

// using namespace std;

// int n;
// vector<int> p, a, visited;
// unordered_set<vector<int>> ss;
// vector<vector<int>> map;

// void dfs(int x, vector<int> &path) {
//     path.push_back(x);
//     visited[x] = 1;
//     for (int i = 2; i <= n; i++) {
//         if (visited[x][i] == 0) {
//             dfs(i, path);
//         }
//     }
// }

// int solve() {
//   bool flag = true;
//   for (int i = 2; i <= n; i++) {
//     if (a[i] != a[1]) {
//       flag = false;
//       break;
//     }
//   }
//   if (flag)
//     return a[1];

//     ss.clear();
//     for (int i = 2; i <= n; i++) {
//         vector<int> path;
//         if (visited[i] != 1) {
//             dfs(i, path);
//         }
//         ss.insert(path);
//     }

//     int res = 0;

//     for (auto graph : ss) {
//         int maxa = INT_MIN, mina = INT_MAX;
//         for (auto i : graph) {
//             maxa = max(a[i], maxa);
//             mina = min(a[i], mina);
//         }

//     }

//   return 3;
// }

// int main() {
//   cin >> n;
//   p.resize(n + 1);
//   a.resize(n + 1);
//   map = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
//   for (int i = 2; i <= n; i++) {
//     cin >> p[i];
//     map[p[i]][i] = 1;
//     map[i][p[i]] = 1;
//   }
//   for (int i = 1; i <= n; i++)
//     cin >> a[i];

//   cout << solve() << endl;

//   return 0;
// }