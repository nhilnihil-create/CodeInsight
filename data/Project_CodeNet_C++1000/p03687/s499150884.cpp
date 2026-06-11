#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll a[26],ans[26];
int main() {
	string s;
	cin>>s;
	for(ll i=0;i<26;i++){
		ans[i]=a[i]=-1;
	}
	for(ll i=0;i<s.size();i++){
		ll now=s[i]-'a';
		ans[now]=max(i-a[now],ans[now]);
		a[now]=i;
	}
	for(ll i=0;i<26;i++){
		if(ans[i]!=-1){
			ans[i]=max(ans[i],ll(s.size()-a[i]));
		}
	}
	ll Ans=inf;
	for(ll i=0;i<26;i++){
		if(ans[i]!=-1){
			Ans=min(Ans,ans[i]);
		}
	}
	cout <<Ans-1;
	// your code goes here
	return 0;
}