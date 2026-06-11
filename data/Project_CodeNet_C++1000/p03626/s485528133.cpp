#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000000000000000
#define mod 1000000007

int main(){
	ll n;cin>>n;
	vector<string> s(2);cin>>s[0]>>s[1];

	ll ans=1,num=0;

	if(s[0][num]==s[1][num]){
		ans=(ans*3)%mod;
	}else{
		ans=(ans*3*2)%mod;
	}

	while(1){
		if(num+1<n && s[0][num]==s[1][num] && s[0][num+1]==s[1][num+1]){
			ans=(ans*2)%mod;
			num++;
		}else if(num+2<n && s[0][num]!=s[1][num] && s[0][num+1]!=s[1][num+1] && s[0][num+2]==s[1][num+2]){
			ans=(ans)%mod;
			num+=2;
		}else if(num+1<n && s[0][num]==s[1][num] && s[0][num+1]!=s[1][num+1]){
			ans=(ans*2)%mod;
			num++;
		}else if(num+2<n && s[0][num]!=s[1][num] && s[0][num+1]!=s[1][num+1] && s[0][num+2]!=s[1][num+2]){
			ans=(ans*3)%mod;
			num+=2;
		}else{
			break;
		}
	}

	cout<<ans<<endl;

	return 0;
}