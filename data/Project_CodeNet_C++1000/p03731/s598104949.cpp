#include<bits/stdc++.h>
#define ford(i,a,b) for(int i=(a);i>=b;i--)
#define rep1(i,a,b) for(int i=(a);(i)<=(b);(i)++)
#define rep(i,a,b) for(int i=(a);(i)<(b);(i)++)
#define ll long long
#define N 200005
#define pql priority_queue<ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define rev(a,n) reverse(a,a+n)
using namespace std;
int n,t,a[N];
int main() {
	cin>>n>>t;
	ll ans=t;
	rep(i,0,n)cin>>a[i];
	rep(i,1,n){
		if(a[i]-a[i-1]>t) ans+=t;
		else ans+=a[i]-a[i-1];
	}
	cout<<ans;
	return 0;
}
