#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long int ll;

ll a[300030];
ll res[100010];
ll res2[100010];
int main(){
	int n; cin >> n;
	for(int i=0;i<n*3;i++){
		cin >> a[i];
	}
	ll sum=0;
	priority_queue<ll,vector<ll>,greater<ll> > q;
	for(int i=0;i<n;i++){
		q.push(a[i]);
		sum+=a[i];
	}
	res[0]=sum;
	for(int i=n;i<2*n;i++){
		q.push(a[i]);
		sum+=a[i];
		int v=q.top();
		q.pop();
		sum-=v;
		res[i-n+1]=sum;
	}
	priority_queue<ll> q2;
	ll sum2=0;
	for(int i=2*n;i<3*n;i++){
		q2.push(a[i]);
		sum2+=a[i];
	}
	res2[n]=sum2;
	for(int i=2*n-1;i>=n;i--){
		q2.push(a[i]);
		sum2+=a[i];
		int v=q2.top();
		sum2-=v;
		q2.pop();
		res2[i-n]=sum2;
	}

	ll ans=res[0]-res2[0];
	for(int i=1;i<=n;i++){
		ans=max(ans,res[i]-res2[i]);
	}
	cout << ans << endl;
}