#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=1e6+5;
vector<ll> V;
int pre[maxn];
int main() {
    string s,ans;cin>>s;
    for(auto x:s) {
    	if(x=='B') {if(ans.length()) ans.pop_back();}
    	else ans.push_back(x);
    }
    cout<<ans<<endl;
    return 0;
}