#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std ;
typedef long long ll ;
const int mod=1000000007 ;

void solve(){
	
	int n ;
	cin>>n ;


	ll ans=1 ;

	for(int i=1;i<=n;i++)	
	{
		ans=(ans*i)%mod ;
	}

	cout<<ans ;
}


int main(){
	
	int y ;

	y=1 ;
	//cin>>y ;

	while(y--)
	{	
		solve() ;
	}

}