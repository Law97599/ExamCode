#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> arr(n);
  int mex = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  std::vector<int> sarr(arr);
  sort(sarr.begin(), sarr.end());
  for (int i = 0; i < n; i++) {
    if (sarr[i] == mex) {
      mex = sarr[i] + 1;
    } else {
      break;
    }
  }

  for (int i = 0; i < n; i++) {
    if (arr[i] <= mex) {
      std::cout << arr[i] << " ";
    } else {
      std::cout << mex << " ";
    }
  }

  return 0;
}