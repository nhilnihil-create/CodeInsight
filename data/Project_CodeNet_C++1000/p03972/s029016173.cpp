#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
//#define MOD 1000000007
#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


int main(){
    int W,H; cin >> W >> H;
    vector<int> p(W),q(H);
    vector<Pi> v;
    rep(i,W) cin >> p[i],v.push_back(Pi(p[i],0));
    rep(i,H) cin >> q[i],v.push_back(Pi(q[i],1));
    sort(v.begin(),v.end());
    int cnt0 = 0,cnt1 = 0;
    ll ans = 0;
    rep(i,W+H){
        if(v[i].second == 0){
            ans += (ll)v[i].first*(H+1-cnt1);
            cnt0++;
        }
        else{
            ans += (ll)v[i].first*(W+1-cnt0);
            cnt1++;
        }
    }
    cout << ans << endl;

}

    

