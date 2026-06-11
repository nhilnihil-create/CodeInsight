#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<iomanip>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
#define LINF (long long)4e18

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;



int main(){
  int N; cin >> N;
  string S1,S2;
  cin >> S1 >> S2;
  ll ans = 0;
  if(S1[0] == S2[0]) ans += 3;
  else ans += 6;
  rep(i,N-1){
     if(S1[i+1] != S1[i] && S1[i+1] != S2[i+1] && S1[i] == S2[i]){
        ans *= 2;
        ans %= MOD;
     }
     else if(S1[i+1] != S1[i] && S1[i+1] != S2[i+1] && S1[i] != S2[i]){
        ans *= 3;
        ans %= MOD;
     }
     else if(S1[i+1] == S2[i+1] && S1[i] == S2[i]){
        ans *= 2;
        ans %= MOD;
     }
  }
  cout << ans << endl;
}

