#include <iostream>
#include <string>
#include <vector>

using namespace std;

int T, n;
string s;

vector<int> solve() {
  int zero = -1, one = -1;
  vector<int> res(s.size());
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      res[i] = one;
      zero = i + 1;
    } else {
      res[i] = zero;
      one = i + 1;
    }
  }
  return res;
}

int main() {
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> n >> s;
    auto res = solve();
    for (auto a : res) {
      cout << a << " ";
    }
    cout << endl;
  }
}