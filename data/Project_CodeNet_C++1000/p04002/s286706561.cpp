#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
const int maxn = 3000005;
const int maxm = maxn*2;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;

int n,m,cnt;
map<pair<int,int>,int>mp;
ll ans[10];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>cnt;
    for(int i = 1;i<=cnt;i++) {
        int x,y; cin>>x>>y;
        for(int i = max(1,x-2);i<=min(x,n-2);i++)
            for(int j = max(1,y-2);j<=min(m-2,y);j++) mp[make_pair(i,j)]++;
    }
    ans[0] = 1ll*(n-2)*(m-2);
    map<pair<int,int>,int> :: iterator it;
    for(auto x : mp) {
        ans[x.second]++;
        ans[0]--;
    }
    for(int i = 0;i<10;i++) cout<<ans[i]<<'\n';
    return 0;
}
