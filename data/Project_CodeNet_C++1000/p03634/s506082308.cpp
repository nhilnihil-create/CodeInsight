#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
ll n,q,k,dx[100010];
vector<pair<ll,ll>>a[100010];
void dep(ll now){
	if(now!=k&&a[now].size()==1){
		return ;
	}
	for(ll i=0;i<a[now].size();i++){
		ll next=a[now][i].first;
		if(next==k){
			continue;
		}
		if(dx[next]!=0){
			continue;
		}
		dx[next]=dx[now]+a[now][i].second;
		dep(next);
	}
}
int main() {
	cin>>n;
	for(ll i=0;i<n-1;i++){
		ll x,y,c;
		cin>>x>>y>>c;
		x--;y--;
		a[x].push_back(make_pair(y,c));
		a[y].push_back(make_pair(x,c));
	}
	cin>>q>>k;
	k--;
	dep(k);
	for(ll i=0;i<q;i++){
		ll x,y;
		cin>>x>>y;
		x--;y--;
		cout << dx[x]+dx[y]<<endl;
	}
	// your code goes here
	return 0;
}