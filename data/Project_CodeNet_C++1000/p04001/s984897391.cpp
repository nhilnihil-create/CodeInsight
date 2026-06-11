#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD=1000000007;

int main() {
    string s;
    cin>>s;
    ll ans=0;
    for(int bit=0;bit<(1<<(int)s.length()-1);bit++){
    	ll m=0;
    	for(int i=0;i<(int)s.length();i++){
    		m=m*10+s[i]-'0';
    		if(bit &(1<<i)){
    			ans+=m;
    			m=0;
    		}
    	}
    	ans+=m;
    }
    cout<<ans<<endl;
    return 0;
}
