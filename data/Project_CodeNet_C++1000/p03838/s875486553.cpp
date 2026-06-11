#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	int x,y;cin>>x>>y;
	int d=abs(abs(x)-abs(y));
	int ans=d;
	if(x>y){
		if(y>0) ans+=2;
		else if(x>=0&&0>=y) ans+=1;
		else ans+=2;
	}
	else{
		if(x>=0) ans+=0;
		else if(y>0&&0>x) ans+=1;
		else ans+=0;
	}

	cout<<ans<<"\n";
}