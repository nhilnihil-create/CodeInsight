#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> p(26,-1);
  rep(i,n){
    int c = s[i]-'a';
    if(p[c]!=-1 && i-p[c]<=2){
      cout << p[c]+1 << " " << i+1 << endl;
      return 0;
    }
    p[c] = i;
  }
  cout << "-1 -1" << endl;
}