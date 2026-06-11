#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[114514];
int main(){
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		ll a,b;
		cin>>a>>b;
		cnt[a]++;
		cnt[b]++;
	}
	for(int i=1;i<=n;i++){
		if(cnt[i]%2){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	return 0;
}
