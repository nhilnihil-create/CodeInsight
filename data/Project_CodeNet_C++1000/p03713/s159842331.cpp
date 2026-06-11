#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
#include<math.h>
#include<assert.h>
// #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long int INFLL = 1001001001001001LL;
constexpr int INFI = 1000000007;
const int mod = 1000000007;

int main(){
  int H,W;
  cin >> H >> W;
  if(H%3==0 || W%3==0){
    cout << 0 << endl;
    return 0;
  }
  ll ans = min(H,W);
  vector<ll> M(3);
  for(ll h=1; h<H; h++){
    M[0] = h*(W/2);
    M[1] = (H-h)*W;
    M[2] = h*W-M[0];
    sort(M.begin(),M.end());
    ans = min(ans,M[2]-M[0]);
  }
  for(ll w=1; w<W; w++){
    M[0] = w*(H/2);
    M[1] = (W-w)*H;
    M[2] = w*H-M[0];
    sort(M.begin(),M.end());
    ans = min(ans,M[2]-M[0]);
  }
  cout << ans << endl;
  return 0;
}
