#include <bits/stdc++.h>
 
using namespace std;
 
#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
#define MOD 1000000007

signed main(){

	lli n,k;
	cin>>n>>k;

	vector<lli> a(n);
	REP(i,0,n)cin>>a[i];
	
	/*data[i], a0からaiまでのプラスのみ足し合わせた数*/
	vector<lli> data(n+1,0);
	data[0] = max(0LL,a[0]);

	REP(i,1,n)data[i] = data[i-1] + max(0LL,a[i]);
	data[n] = data[n-1];
	
	lli sum = 0;
	/*先頭k個を黒にしたときの尺取りを行う*/
	REP(i,0,k)sum += a[i];
	
	lli ans = -INF;
	
	/*黒で塗った時*/
	ans = max(ans,max(sum,0LL)+ data[n-1]-data[k-1]);

	for(lli i=k;i<n;i++){
		sum += a[i];
		sum -= a[i-k];
		ans = max(ans,max(sum,0LL) + data[n-1] - data[i] + data[i-k]);
	}

	cout<<ans<<endl;

	return 0;
}