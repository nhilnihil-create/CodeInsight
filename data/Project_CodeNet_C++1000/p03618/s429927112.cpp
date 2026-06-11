#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll cnt[30];
int main(){
	string s;
	cin>>s;
	ll n=s.size();
	for(int i=0;i<n;i++){
		cnt[s[i]-'a']++;
	}
	ll ans=n*(n-1)/2+1;
	for(int i=0;i<26;i++)ans-=cnt[i]*(cnt[i]-1)/2;
	cout<<ans;
	return 0;
}
