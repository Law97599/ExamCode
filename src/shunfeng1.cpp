#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  long long int depth = log2(n);
  long long int res = 1;
  for (int i = 1; i < depth; i++) {
    long long int cur = pow(2, i) * (i + 1);
    res += cur;
  }
  res += ((depth + 1) * (n - pow(2, depth) + 1));
  cout << res << endl;
  return 0;
}

// 100 %
// 求二分查找最坏情况下，找到所有位置的比较次数。