#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
	string s;cin>>s;
	bool flag=1;
	int ans=inf;
	rep(i,s.size()-1){
		if(s[i]!=s[i+1]){
			flag=0;
			break;
		}
	}
	if(flag){
		cout<<0<<"\n";
		return 0;
	}

	for(char c='a';c<='z';c++){
		string t=s;
		int current_size=t.size(),cnt=0;
		while(1){
			rep(i,current_size-1){
				if(t[i]==c||t[i+1]==c) t[i]=c;
			}
			//cout<<t<<"\n";
			cnt++;
			current_size--;

			flag=1;			
			rep(i,current_size-1){
				if(t[i]!=t[i+1]){
					flag=0;
					break;
				}
			}
			if(flag) break;
		}
		ans=min(ans,cnt);
	}
	cout<<ans<<"\n";
}