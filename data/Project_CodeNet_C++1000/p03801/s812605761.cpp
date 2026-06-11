#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll; typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename A,size_t N,typename T>void Fill(A(&array)[N],const T &val){fill((T*)array, (T*)(array+N), val);}
const int inf = 0x3fffffff; const ll INF = 0x3fffffffffffffff;
//template end



int main(){
    int n; scanf("%d",&n); ll ans[100010]={};
    vector<P> a(n);
    rep(i,0,n)scanf("%lld",&a[i].first),a[i].second=-i;
    sort(ALL(a),greater<P>()); a.push_back({0,0});
    ll pre[2]={a[0].first,a[0].second};
    rep(i,1,n+1){
        ans[-pre[1]]+=i*(pre[0]-a[i].first),pre[0]=a[i].first,chmax(pre[1],a[i].second);
    }
    rep(i,0,n)printf("%lld\n",ans[i]);
    return 0;
}