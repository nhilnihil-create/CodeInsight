#include<bits/stdc++.h>
#define Speed_UP  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define 	pb	push_back 
#define 	ff	first 
#define 	ss	second 
#define sz(x) (int)x.size()
#warning Remeber to change t
using namespace std;
typedef long long ll;
inline void setIO(string name="") {
	#ifndef ONLINE_JUDGE 
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
	#endif
	}
	ll const mx=1e5+7;
	ll freq[mx];
int main(){
	Speed_UP
	ll t;
	t=1;
	while(t--){
		ll n;
		cin>>n;
		for(int i=0;i<n;i++){
			ll x;
			cin>>x;
			freq[x]++;
			freq[x+1]++;
			freq[x-1]++;
		}
		ll ans=0;
		ll cand=0;
		for(int i=0;i<mx;i++){
			if(freq[i]>ans){
				ans=freq[i];
				cand=i;
			}
		}
		cout<<ans;
		
		
		
	}





}
