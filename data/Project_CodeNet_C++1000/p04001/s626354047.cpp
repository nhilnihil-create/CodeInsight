#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e6+5;
multiset<ll> S[20];
char buff[20]; 
ll PW10[20]={1};
int main() {
	for(int i=1;i<=10;i++) PW10[i]=PW10[i-1]*10;
	cin>>(buff+1);int len=strlen(buff+1);
    for(int i=1;i<=len;i++) buff[i]-='0';
    S[0].insert(0);
    for(int i=1;i<=len;i++) {
    	ll now=0;
    	for(int j=i;j>=1;j--) {
    		now=now+PW10[i-j]*buff[j];
    		for(auto x:S[j-1]) S[i].insert(now+x);
    	}
    }
    ll ans=0;
    for(auto x:S[len]) ans+=x;
    cout<<ans<<endl;
    return 0;
}