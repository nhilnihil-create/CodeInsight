#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>
#include <chrono>
#include <random>
#include <bitset>

using namespace std;

#define sz(x) (int) x.size()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end())
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x)) 
#define y1 aksjdaskdjksjfksdjf
#define left kdnvldvoiwejifejg
#define right lkdsjflksdjfdjfk
#define prev asdasfsadjkjsdfjs
#define tm aklsjdasjdasjdkdjjf
#define lcm hddalkwjeidjjhasda
#define random_shuffle asdasdd

int n;
string s;

void reverse(int l, int r) {
  while (l < r) {
    swap(s[l], s[r]);
    l++; r--;
  }
}

bool isPalindrome(int l, int r) {
  while (l < r) {
    if (s[l] != s[r]) {
      return false;
    }
    l++; r--;
  }
  return true;
}

int main() { 

  getline(cin, s);
  n = sz(s);

  long long ans = 1 + 1ll * n * (n + 1) / 2;

  // map<string, vector<string>> res;
  // set<string> st;
  // for (int i = 0; i < n; i++) {
  //   for (int j = i; j < n; j++) {
  //     reverse(i, j);
  //     st.insert(s);
  //     res[s].push_back(to_string(i) + " " + to_string(j) + " " + to_string(isPalindrome(i, j)));
  //     // cout << i << " " << j << " " << s << endl;
  //     reverse(i, j);
  //     // if (isPalindrome(i, j)) {
  //     //   ans--;
  //     // }
  //   }
  // }
  // for (auto p : res) {
  //   cout << p.first << endl;
  //   for (auto x : p.second) {
  //     cout << x << endl;
  //   }
  //   cout << endl;
  // }
  // cout << "Right count is " << sz(st) << endl;

  // for (int i = 0; i < n; i++) {
  //   for (int j = i; j < n; j++) {
  //     for (int k = i; k <= j; k++) {
  //       for (int l = k; l < n; l++) {
  //         if (k == i && l == j) {
  //           continue;
  //         }
  //         if (isPalindrome(i, j) && isPalindrome(k, l)) {
  //           ans--;
  //         }
  //       }
  //     }
  //   }
  // }

  map<char, int> cnt;
  for (int i = 0; i < n; i++) {
    cnt[s[i]]++;
    ans -= cnt[s[i]];
  }

  cout << ans << endl;

  return 0;
}
