#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  string s,t;
  cin >> n >> s >> t;
  rep(i,0,n){
    if(s.substr(i) == t.substr(0,n-i)){
      cout << n+i << endl;
      return 0;
    }
  }
  cout << 2*n << endl;
}