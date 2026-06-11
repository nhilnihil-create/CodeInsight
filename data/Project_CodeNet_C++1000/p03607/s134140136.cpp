#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll MX = 1000000005;

int main(){
  int n;
  cin >> n;

  vector<bool> exist(MX,false);
  int ans = 0;
  rep(i,n){
    int a;
    cin >> a;
    exist[a] = !(exist[a]);
    if(exist[a]==true) ans++;
    else ans--;
  }

  cout << ans << endl;

  return 0;
}