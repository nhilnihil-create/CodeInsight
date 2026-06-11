#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
typedef long long ll;
typedef long double ld;
int main(){
    ll n,m;cin>>n>>m;
    ll a,b;
    vector<vector<ll>> v(n+1);
    REP(i,m){
        cin>>a>>b;
        v[a].push_back(b);
    }
    ll from=1;
    string ans="IMPOSSIBLE";
    REP(i,SIZE(v[1])){
        ll to=v[1][i];
        if(find(ALL(v[to]),n)!=v[to].end()){
            ans="POSSIBLE";
        }
    }
    cout<<ans<<endl;
    return 0;
}
