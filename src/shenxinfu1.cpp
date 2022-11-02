#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> strSplit(const string& str, char delim = ' ') {
  stringstream ss(str);
  string item;
  vector<string> elems;
  while (getline(ss, item, delim)) {
    if (!item.empty()) {
      elems.push_back(item);
    }
  }
  return elems;
}

int main() {
  string s;
  getline(cin, s);
  vector<string> a = strSplit(s);
  auto len = a.size();
  vector<long long> arr(len);
  for (int i = 0; i < len; i++) {
    auto n = stoll(a[i]);
    arr[i] = n;
  }

  int i = 0, j = 1, k = arr[len - 1];
  while (i < len - 1) {
    if (j == k) {
      cout << to_string(arr[i]);
      break;
    }
    if (i + j == len - 1) {
      cout << to_string(arr[i]);
      break;
    }
    if (arr[i] < arr[i + j]) {
      i += j;
      j = 1;
    } else {
      j++;
    }
  }

  return 0;
}