#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr;

int solve() { return 0; }

int main() {
  cin >> n;
  arr.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << solve() << endl;

  return 0;
}