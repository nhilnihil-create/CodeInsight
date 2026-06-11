#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int maxn=1e6+5;
vector<ll> V;
string s[105];
int main() {
    int n,l;cin>>n>>l;
    for(int i=1;i<=n;i++) cin>>s[i];
    sort(s+1,s+1+n);
	for(int i=1;i<=n;i++) cout<<s[i];
    return 0;
}