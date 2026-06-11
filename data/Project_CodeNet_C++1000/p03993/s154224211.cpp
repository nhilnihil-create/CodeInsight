#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll (i)=0; (i)<(n); (i)++)
#define rrep(i,n) for(ll i = 1; i <= (n); ++i)
#define pll pair<ll,ll> 
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
int inf=1000001000;
ll INF=100000000000000000;
ll MOD=1000000007;
//g++ code.cpp   ./a.out 

int main() {
   ll n;
   cin >> n;
   vector<ll> a(n);
   rep(i,n){
      cin >> a[i];
      a[i]--;
   }
   ll ans=0;
   rep(i,n){
      if(a[a[i]]==i) ans++;
   }
   cout << ans/2 << endl;
}

