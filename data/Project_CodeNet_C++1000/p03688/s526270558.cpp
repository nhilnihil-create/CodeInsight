#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	map<ll,ll>a;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		a[x]++;
	}
	bool ch=false;
	if(a.size()==1){
		auto itr=a.begin();
		ll key=itr->first;
		if(key==n-1){
			ch=true;
		}
		if(key<=n/2){
			ch=true;
		}
	}
	else if(a.size()==2){
		auto itr=a.begin();
		ll key1=itr->first;
		ll val1=itr->second;
		itr++;
		ll key2=itr->first;
		ll val2=itr->second;
		//cout << val2<<val1<<key2;
		if(key2==key1+1&&key2>val1&&(key2-val1)*2<=val2){
			ch=true;
		}
	}
	cout <<(ch? "Yes":"No");// your code goes here
	return 0;
}