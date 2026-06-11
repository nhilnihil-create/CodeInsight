#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  string str;
  cin >> str;
  int N = str.size();
  vector<int> vec;
  int c = 0;
  rep(i, N) {
    if(str.at(i) == '0') {
      vec.push_back(0);
      c++;
    }
    if(str.at(i) == '1') {
      vec.push_back(1);
      c++;
    }
    if(str.at(i) == 'B') {
      if(c > 0) {
        c--;
        vec.pop_back();
      } 
    }
  }
  rep(i, vec.size()) {
    cout << vec.at(i);
  }
}