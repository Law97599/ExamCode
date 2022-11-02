#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  cin >> n;
  string res = "";
  int i = 10;
  while (n != 0) {
    while (n < pow(2, i)) i--;
    n -= pow(2, i);
    res += 'a' + i;
  }
  cout << res << endl;
  return 0;
}