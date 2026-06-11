#include <bits/stdc++.h>
#include <map>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int main(){
  
  int N;
  ll L, T;
  cin >> N >> L >> T;
  vector<ll> X(N);
  vector<int> W(N);
  vector<ll> Now(N);
  rep(i,N) cin >> X[i] >> W[i];
  rep(i,N){
    if (W[i] == 1) Now[i] =(X[i] + T) % L;
    else Now[i] =((X[i] - T) % L + L) % L;
  }
  sort(Now.begin(), Now.end());
  ll cnt = 0;
  rep(i,N){
    if(W[i] == 1)  cnt -= (X[i] + T) / L;    
    else cnt += (T -(X[i] + 1 ) + L) / L;
  }
  cnt = (cnt % N + N) % N;  
  vector<ll>ans(N);
  rep(i,N) ans[(i+cnt)%N] = Now[i];  
  rep(i,N) cout << ans[i] << endl;
 
}
