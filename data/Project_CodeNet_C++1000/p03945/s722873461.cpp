#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
string s;
ll ans;
int main(void){
	cin>>s;
	for(int i=1;i<s.size();i++){
		if(s[i-1]!=s[i]){
			ans++;
		}
	}
	cout<<ans<<endl;
	
}
