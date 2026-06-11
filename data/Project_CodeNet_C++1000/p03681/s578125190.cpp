#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main(){
  ll n,m;
  cin>>n>>m;
  if (n-m>1||m-n>1){
    cout<<0<<endl;
    return 0;
	}
  else{
     ll ans=1;
     for (ll i=2;i<=n;i++){
        ans=(ans*i)%1000000007;
		}
     for (ll i=2;i<=m;i++){
		ans=(ans*i)%1000000007;
		}

	 if(n==m){
         ans=(ans*2)%1000000007;
		}
      cout<<ans<<endl;
	}
}
