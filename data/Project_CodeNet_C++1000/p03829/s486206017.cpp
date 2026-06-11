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
    ll n,a,b;cin>>n>>a>>b;
    vector<ll> v(n);
    ll cost=0;
    REP(i,n)cin>>v[i];
    REP(i,n-1){
        ll l=v[i], r=v[i+1];
        if(b<(r-l)*a){
            cost+=b;
        }else{
            cost+=(r-l)*a;
        }
    }
    cout<<cost<<endl;
    return 0;
}
