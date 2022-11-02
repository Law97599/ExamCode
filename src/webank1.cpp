#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<string> a;

int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), [](string a, string b) {
    return a.size() > b.size() || (a.size() == b.size() && a > b);
  });
  string res = "";
  sort(a.begin(), a.begin() + min(n, 3),
       [](string a, string b) { return a > b; });
  for (int i = 0; i < min(n, 3); i++) res += a[i];
  cout << res;
  return 0;
}