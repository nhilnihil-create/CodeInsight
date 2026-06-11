#include<iostream>
#include<numeric>
#include<queue>
using namespace std;
typedef long long ll;
int main(){
	int n;
	cin >> n;
	vector<ll> a(3*n);
	for(int i=0;i<3*n;i++){
		cin >> a[i];
	}

	ll S=accumulate(a.begin(),a.begin()+n,0LL);
	vector<ll> S1(n+5);
	S1[0]=S;
	priority_queue<ll,vector<ll>,greater<ll>> que1(a.begin(),a.begin()+n);
	for(int i=n;i<2*n;i++){
		que1.push(a[i]);
		ll val=que1.top();que1.pop();
		S+=(a[i]-val);
		S1[i-n+1]=S;
	}

	S=accumulate(a.begin()+2*n,a.end(),0LL);
	vector<ll> S2(n+5);
	S2[0]=S;
	priority_queue<ll> que2(a.begin()+2*n,a.end());
	for(int i=1;i<=n;i++){
		que2.push(a[2*n-i]);
		ll val=que2.top();que2.pop();
		S+=(a[2*n-i]-val);
		S2[i]=S;
	}

	ll ans=-1e18;
	for(int i=0;i<=n;i++){
		ans=max(ans,S1[i]-S2[n-i]);
	}
	cout << ans << endl;
	return 0;
}
