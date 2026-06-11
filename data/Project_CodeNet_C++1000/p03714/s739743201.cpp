#include<bits/stdc++.h>
#define INF 2147483647
#define LLINF 9223372036854775807
typedef long long ll;
using namespace std;
ll ans[500010];
ll cnt[500010];
ll a[500010];
priority_queue<ll,vector<ll>,greater<ll> > q;
priority_queue<ll,vector<ll>,greater<ll> > p;
ll n;
void run(){
	cin>>n;
	for(int i=0;i<3*n;i++)cin>>a[i];
	ll sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
		q.push(a[i]);
	}
	ans[n-1]=sum;
	for(int i=n;i<2*n;i++){
		sum+=a[i];
		q.push(a[i]);
		sum-=q.top();
		q.pop();
		ans[i]=sum;
	}
	sum=0;
	for(int i=3*n-1;i>=2*n;i--){
		sum+=a[i];
		p.push(-a[i]);
	}
	cnt[2*n]=sum;
	for(int i=2*n-1;i>=n;i--){
		sum+=a[i];
		p.push(-a[i]);
		sum-=-p.top();
		p.pop();
		cnt[i]=sum;
	}
	ll mx=-LLINF;
	for(int i=n-1;i<2*n;i++){
		mx=max(mx,ans[i]-cnt[i+1]);
	}
	cout<<mx<<endl;
}
int main(){
	run();
	return 0;
}
