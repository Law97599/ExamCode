#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

string s;

int solve() {
  map<int, int> hm;
  hm[0] = 1;
  long long res = 0;
  int cur = 0;
  for (auto c : s) {
    cur ^= 1 << (c - 'a');
    for (int i = 0; i < 26; i++) {
      res += hm[cur ^ (1 << i)];
    }
    hm[cur]++;
  }
  return res;
}

int main() {
  cin >> s;
  cout << solve() << endl;

  return 0;
}