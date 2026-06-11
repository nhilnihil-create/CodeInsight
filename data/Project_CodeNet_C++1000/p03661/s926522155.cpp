#include "bits/stdc++.h"
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define ALL(s) s.begin(),s.end()
const int M=100010;
int INF=1000000007;
using ll=long long;

int main(){
	int n,a[200010];
	ll l=0,r=0,ans=1e15;
	cin>>n;
	rep(i,0,n){
		cin>>a[i];
		r+=a[i];
	}
	rep(i,0,n-1){
		l+=a[i],r-=a[i];
		ans=min(ans,abs(l-r));
	}
	cout<<ans<<endl;
}
