#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define eps 1e-6
#define eq(x,y) (fabs((x)-(y)) < eps)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
const int mod = 998244353;
long double PI = acosl(-1);
const ll infl = 1e18+100;
const int inf = 2e9+100;
const int nmax = 2e5+5;
const int MAXLG = log2(nmax)+1;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll n;
    cin>>n;
    vector<int>res;
    int sz;
    for(int i=60; i>=0; i--){
        ll val = (1LL<<i) - 1;
        if(val <= n){
            for(int j=1; j<=i; j++) res.push_back(j);
            for(int j=1; j<=i; j++) res.push_back(j);
            n -= val;
            sz = i;
            break;
        }
    }
    int extra = 0, cur = sz;
    for(int i=60; i>=0; i--){
        if(n & (1LL<<i)){
            int bame = sz - i + extra;
            cur++;
            res.insert(res.begin() + sz + extra, cur);
            extra++;
            res.insert(res.begin() + bame, cur);
        }
    }
    cout<<res.size()<<"\n";
    for(int x : res) cout<<x<<" ";
}
/*

*/
