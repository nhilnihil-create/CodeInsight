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

	lli flag=0;
	vector<lli> a(n);
	REP(i,0,n){
		cin>>a[i];
		if(a[i]>=0)flag++;
	}

	/*data[i], a0からaiまでのプラスのみ足し合わせた数*/
	vector<lli> data(n+1,0);
	data[0] = max(0LL,a[0]);

	REP(i,1,n)data[i] = data[i-1] + max(0LL,a[i]);

	lli sum = 0;
	/*先頭k個を黒にしたときの尺取りを行う*/
	REP(i,0,k)sum += a[i];
	if(DEBUG)cout<<"first sum ="<<sum<<endl;

	data[n] = data[n-1];
	lli ans = -INF;
	if(flag==n)ans = data[n];
	/*黒で塗った時*/
	ans = max(ans,sum + data[n-1]-data[k-1]);
	if(DEBUG)cout<<"BALL ans="<<ans<<endl;
	/*白で塗った時*/
	ans = max(ans,data[n-1]-data[k-1]);
	if(DEBUG)cout<<"WALL ans="<<ans<<endl;

	if(DEBUG){
		for(lli i=0;i<n;i++){
			cout<<data[i]<<endl;
		}
	}

	if(DEBUG)cout<<"ans="<<ans<<endl;
	for(lli i=k;i<n;i++){
		if(DEBUG)cout<<"i="<<i<<endl;
		sum += a[i];
		sum -= a[i-k];
		if(DEBUG)cout<<"sum="<<sum<<endl;
		lli next = sum + data[n-1] - data[i];
		if(i-k-1>=0)next += data[i-k];
		ans = max(ans,next);
		if(DEBUG)cout<<"BALL ans="<<ans<<endl;
		ans = max(ans,data[n-1] - data[i] + data[i-k]);
		if(DEBUG)cout<<"WALL ans="<<ans<<endl;
	}

	cout<<ans<<endl;

	return 0;
}