#include <iostream>
#include <string>

using namespace std;
int n, m;
string s;
int main() {
  cin >> n >> m;
  cin >> s;
  int i = 0;

  while (m--) {
    while (i < n) {
      if (s[i] == 'B') {
        s[i] = 'A';
        i++;
        break;
      }
      i++;
    }
  }
  cout << s << endl;

  return 0;
}