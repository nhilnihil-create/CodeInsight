#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define rep(i,n) for(int i=1;i<=(n);i++)
#define rep0(i,n) for(int i=0;i<(n);i++)

const ll INF=1e9+7;
priority_queue<ll> q2;
priority_queue<ll, vector<ll>, greater<ll> > q1;
ll n,g1,g2,dp1[200001],dp2[300001],maxf=-1e18+7;
ll a[300001];
int main()
{
	/*freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);*/
	cin>>n;
	rep(i,n*3){
		cin>>a[i];
	}
	rep(i,n*2){
		if(i<=n){
			q1.push(a[i]);
			g1+=a[i];
			dp1[i]=g1;
		}
		else{
			q1.push(a[i]);
			g1+=a[i];
			g1-=q1.top();
			dp1[i]=g1;
			q1.pop();
		}
//		cout<<dp1[i]<<' ';
	}
//	cout<<endl;
	for(ll i=n*3;i>=n+1;i--){
		if(i>=n*2+1){
			q2.push(a[i]);
			g2+=a[i];
			dp2[i]=g2;
		}
		else{
			q2.push(a[i]);
			g2+=a[i];
			g2-=q2.top();
			dp2[i]=g2;
			q2.pop();
		}
//		cout<<dp2[i]<<' ';
	}
//	cout<<endl;
	for(ll i=n;i<=n*2;i++){
		maxf=max(maxf,dp1[i]-dp2[i+1]);
	}
	cout<<maxf;
	return 0;
}