#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;
using M = map<int, int>;

int main()
{
  int n;
  cin >> n;
  int ans = 0;
  M mp;
  rep(i, n){
    int x;
    cin >> x;
    if(mp[x] == 0){
      mp[x]++;
      ans++;
    }
    else{
      mp[x]--;
      ans--;
    }
  }
  cout << ans << endl;

       

  return 0;
}