#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	string s;
	cin>>s;
	ll ans=0;
	for(int i=0;i<s.size();i++){
		bool me;
		if(i%2==0){
			me=false;
		}
		else{
			me=true;
		}
		char now=s[i];
		if(now=='g'){
			if(me){
				ans++;
			}
		}
		else{
			if(me==false){
				ans--;
			}
		}
	}
	cout << ans;
	return 0;
}