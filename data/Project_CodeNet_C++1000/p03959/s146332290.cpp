#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
#define MOD 1000000007

signed main(){

	lli n;
	cin>>n;
	vector<lli> t(n+2),a(n+2);
	REP(i,0,n){
		cin>>t[i+1];
	}	
	REP(i,0,n){
		cin>>a[i+1];
	}

	
	if(t[n] != a[1]){
		cout<<0<<endl;
		return 0;
	}


	vector<lli> high(n+2),low(n+2);

	t[0] = 0;
	t[n+1] = INF;
	a[0] = INF;
	a[n+1] = 0;

	for(lli i=1; i<=n;i++){
		if(t[i] != t[i-1] && a[i] != a[i+1]){
			if(t[i]!=a[i]){
				if(DEBUG)cout<<"i="<<i<<" t[i]="<<t[i]<<" a[i]="<<a[i]<<endl;
				cout<<0<<endl;
				return 0;
			}
			high[i] = t[i];
			low[i] = t[i];
		}
		else if(t[i] != t[i-1]){
			high[i] = t[i];
			low[i] = t[i];
			if(high[i] > a[i]){
				cout<<0<<endl;
				return 0;
			}
		}
		else if(a[i] != a[i+1]){
			high[i] = a[i];
			low[i] = a[i];
			if(high[i] > t[i]){
				cout<<0<<endl;
				return 0;
			}
		}
		//else(t[i]==t[i-1] && a[i]==a[i+1]){
		else{
			high[i] = min(t[i],a[i]);
			low[i] = 1;
		}
	}

	lli ans = 1;
	for(lli i=1;i<=n;i++){
		if(DEBUG)cout<<"i="<<i<<" high[i]="<<high[i]<<" low[i]="<<low[i]<<endl;
		ans = (ans*(high[i]-low[i]+1) )%MOD;
	}
	cout<<ans<<endl;


	return 0;
}