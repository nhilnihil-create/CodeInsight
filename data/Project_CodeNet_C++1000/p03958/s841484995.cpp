#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,k;
	cin>>n>>k;
	priority_queue<ll>q;
	for(ll i=0;i<k;i++){
		ll now;
		cin>>now;
		q.push(now);
	}
	ll ans=0;
	while(q.size()>1){
		ll next=q.top();
		next--;
		q.pop();
		ll nnext=q.top();
		nnext--;
		q.pop();
		if(nnext!=0){
			q.push(nnext);
		}
		if(next!=0){
			q.push(next);
		}
	}
	cout << q.top()-1;
	// your code goes here
	return 0;
}