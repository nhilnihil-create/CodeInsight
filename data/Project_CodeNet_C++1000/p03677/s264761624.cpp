#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define int long long
#define mp make_pair
#define inf 1000000007
using namespace std;
ll sum[214514];
int n,m;
signed main(){
	cin>>n>>m;
	vector<int> a;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.pb(x);
	}
	for(int i=0;i<n-1;i++){
		int st = a[i];
		int gl = a[i+1];
		if( st < gl){
			sum[st+2]--;
			sum[gl+1]++;
		}
		else{
			sum[st+2]--;
			sum[gl+m+1]++;
		}
	}
	for(int i=1;i<=2*m;i++){
		sum[i] += sum[i-1];
	}
	for(int i=m+1;i<=2*m;i++){
		sum[i-m] += sum[i];
	}
	for(int i=0;i<n-1;i++){
		int st = a[i];
		int gl = a[i+1];
		int bd = gl+1;
		if(gl==m)bd=1;
		if(st<gl){
			sum[bd] += gl-st-1;
		}
		else{
			sum[bd] += gl+m-st-1;
		}
	}
	ll ans = 1000000000000LL;
	ll cur = 0;
	for(int i=0;i<n-1;i++){
		int st = a[i];
		int gl = a[i+1];
		if(st<gl){
			cur += gl -st;
		}
		else{
			cur += gl;
		}
	}
	if(ans > cur)ans = cur;
	for(int i=2;i<=m;i++){
		cur += sum[i];
		if(ans > cur)ans = cur;
		//cout<<cur<<endl;
	}
	cout<<ans<<endl;
	return 0;
}