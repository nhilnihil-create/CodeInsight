#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  string s;
  cin >> n >> s;
  int x = 0,ans = 0;
  rep(i,0,n){
    if(s[i] == 'I') x++;
    else x--;
    ans = max(ans,x);
  }
  cout << ans << endl;
}