#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int h, w;
  cin >> h >> w;
  vector<char> c(200, 0);
  for(int i = 0; i < h; i++) {
    string tmp;
    cin >> tmp;
    for(int j = 0; j < w; j++) {
      c[tmp[j]]++;
    }
  }
  if(h % 2 == 0 && w % 2 == 0) {
    for(int i = 0; i < 200; i++) {
      if(c[i] % 4 != 0) {
        cout << "No\n";
        return 0;
      }
    }
    cout << "Yes\n";
  } else if(h % 2 != w % 2) {
    for(int i = 0; i < 200; i++) {
      if(c[i] % 2 != 0) {
        cout << "No\n";
        return 0;
      }
    }
    int cnt = 0;
    for(int i = 0; i < 200; i++) {
      if(c[i] % 4 != 0) {
        cnt += 2;
      }
    }
    if(h % 2 == 0) {
      if(cnt > h) {
        cout << "No\n";
        return 0;
      }
    } else {
      if(cnt > w) {
        cout << "No\n";
        return 0;
      }
    }
    cout << "Yes\n";
  } else {
    int one = 0;
    for(int i = 0; i < 200; i++) {
      if(c[i] % 2 != 0) {
        one++;
      }
    }
    if(one != 1) {
      cout << "No\n";
      return 0;
    }
    int cnt = 0;
    for(int i = 0; i < 200; i++) {
      if(c[i] % 2 != 0) {
        continue;
      } else if(c[i] % 4 != 0) {
        cnt += 2;
      }
    }
    if(cnt > h + w - 2) {
      cout << "No\n";
      return 0;
    }
    cout << "Yes\n";
  }
  return 0;
}