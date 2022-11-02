#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  long long n;
  vector<long long> a;
  cin >> n;
  a.resize(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }

  long long res = -1;
  vector<long long> w(n, 1);
  for (long long i = 1; i < n; i++) {
    if (a[i] < a[i - 1]) {
      w[i] = w[i - 1] + 1;
    } else {
      w[i] = 1;
    }
  }

  for (long long i = n - 2; i >= 0; i--) {
    if (a[i] < a[i + 1]) {
      w[i] += w[i + 1];
    }
  }

  for (auto c : w) {
    res = max(res, c);
  }

  cout << res << endl;

  return 0;
}