// In the name of god
#include <bits/stdc++.h>
#pragma GCC optimize("02")
using namespace std;
using ll =long long ;
const ll maxn=1e5+5;
ll n,a[maxn],ans;
map <ll,ll> mp;
int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mp[a[i]]=i;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if((abs(i-mp[a[i]]))%2==1){
			ans++;
		}
	}
	cout<<ans/2;
}
