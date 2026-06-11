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
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;



int main(){
    int H,W,N; cin >> H >> W >> N;
    map<Pi,int> mp;
    rep(i,N){
        int a,b; cin >> a >> b;
        a--; b--;
        rep(j,3)rep(k,3){
            if(a-j >= 0 && b-k >= 0 && a-j+2 < H && b-k+2 < W){
                mp[Pi(a-j,b-k)]++;
            }
        }
    }
    vector<ll> ans(10);
    for(auto u : mp){
        ans[u.second]++;
    }
    ll sum = 0;
    rep(i,10) sum += ans[i];
    ans[0] = (ll)(H-2)*(W-2)-sum;
    rep(i,10){
        cout << ans[i] << endl;
    }
}
