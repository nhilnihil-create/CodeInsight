#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
//グリッド：（典型）dp,dfs,bfs,最短経路,その他
ll cnt[26];
int main(){
    int h,w;cin>>h>>w;
    rep(i,h){
        rep(j,w){
            char c;cin>>c;
            cnt[c-'a']++;
        }
    }
    vl req;
    rep(i,(h+1)/2){
        rep(j,(w+1)/2){
            int i2=h-1-i,j2=w-1-j;
            ll tmp=(i2==i?1:2)*(j2==j?1:2);
            req.push_back(tmp);
        }
    }
    sort(req.rbegin(),req.rend());
    rep(i,(int)req.size()){
        bool ok=false;
        rep(j,26){
            if(cnt[j]>=req[i]){
                cnt[j]-=req[i];
                ok=true;
                break;
            }
        }
        if(!ok){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}