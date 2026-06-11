#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)

typedef long long ll;
typedef pair<ll, ll>  pll;

int main(){
    ll H, W;
    cin >> H >> W;
    vector<pll> roads;
    REP(i, H){
        ll p;
        cin >> p;
        roads.push_back({p, 0});
    }
    REP(i, W){
        ll p;
        cin >> p;
        roads.push_back({p, 1});
    }
    sort(roads.begin(), roads.end());
    ll a = H+1;
    ll b = W+1;
    ll res = 0;
    REP(i, roads.size()){
        if(roads[i].second==0){
            res += roads[i].first*b;
            a--;
        }
        if(roads[i].second==1){
            res += roads[i].first*a;
            b--;
        }
    }
    cout << res << endl;
    return 0;
}