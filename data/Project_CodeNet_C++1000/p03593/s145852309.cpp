#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
	ll ch[26];
int main() {
	ll h,w;
	cin>>h>>w;

	for(ll i=0;i<h;i++){
		for(ll j=0;j<w;j++){
			char now;
			cin>>now;
			ch[now-'a']++;
		}
	}
	bool ans=true;
	ll cnt1=0;
	for(ll i=0;i<26;i++){
		if(ch[i]%2!=0){
			cnt1++;
			ch[i]--;
		}
	}
	if(cnt1>=2){
		ans=false;
	}
	if(cnt1==1){
		if(h%2==0||w%2==0){
			ans=false;
		}
	}
//	cout << ans<<endl;
	ll cnt2=0;
	for(ll i=0;i<26;i++){
		if(ch[i]%4!=0){
			cnt2++;
		}
	}
	if(cnt2!=0){
		ll now=0;
		if(h%2!=0){
			now+=w/2;
		}
		if(w%2!=0){
			now+=h/2;
		}
		if(cnt2>now){
			ans=false;
		}
	}
	cout << (ans?"Yes":"No");
	// your code goes here
	return 0;
}