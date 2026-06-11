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

int main(){
	Speed_UP
	ll t;
	t=1;
	while(t--){
		string s;
		cin>>s;
		ll n=sz(s);
		for(int i=n-2;i>=0;i-=2){
			if(s.substr(0,i/2)==s.substr(i/2,i/2)){
				cout<<i;
				return 0;
			}
		}
		cout<<0;
		
		
		
	}





}
