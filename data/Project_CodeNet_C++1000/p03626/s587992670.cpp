#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
int main(){
  int n;
  string s,t;
  cin >> n >> s >> t;
  vi blocks;
  rep(i, n){
    if(s[i] == t[i]){
      blocks.push_back(1);
    }else{
      blocks.push_back(2);
      i++;
    }
  }
  ll ans = 3 * blocks[0];
  for(int i = 0; i < n - 1; i++){
    if(blocks[i] == 1 && blocks[i + 1] == 1){
      ans *= 2;
      ans %= mod;
    }
    if(blocks[i] == 1 && blocks[i + 1] == 2){
      ans *= 2;
      ans %= mod;
    }
    //if(blocks[i] == 2 && blocks[i + 1] == 1){
    //}
    if(blocks[i] == 2 && blocks[i + 1] == 2){
      ans *= 3;
      ans %= mod;
    }
  }
  cout << ans << endl;
}