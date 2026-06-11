#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n,ans = 0,a;
  cin >> n;
  if(n == 1){
    cout << 1 << endl;
    return 0;
  }
  rep(i,1,n+1){
    int cnt = 0,t = i;
    while(t%2 == 0){
      t /= 2;
      cnt++;
    }
    if(cnt > ans){
      ans = cnt;
      a = i;
    }
  }
  cout << a << endl;
}