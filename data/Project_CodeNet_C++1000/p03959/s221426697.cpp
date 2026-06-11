#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <math.h>
#include <complex>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <functional>
#include <assert.h>
#define int long
#define ll long long
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define SZ(x) x.size()
#define fi first
#define se second
const int INF = 1e9;
const int MOD = 1e9+7;
using namespace std;

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class T>
inline bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T>
inline bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout<<fixed<<setprecision(20);

    int N; cin >> N;
    vc<pair<bool,int>> v;
    int A[N],B[N];
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> B[i];
    rep(i,N){
        if(!i || A[i-1]!=A[i]){
            v.eb(true,A[i]);
        } else {
            v.eb(false,A[i]);
        }
    }
    int ans=1;
    rep(i,N){
        if(v[N-i-1].fi && v[N-i-1].se>B[N-i-1]){
            ans=0; break;
        }
        if(!i || B[N-i-1]!=B[N-i]){
            if(B[N-i-1]>v[N-i-1].se) {
                ans=0; break;
            }
            v[N-i-1].fi=true;
        }
        chmin(v[N-i-1].se,B[N-i-1]);
    }
    if(ans==0) cout << ans << endl;
    else {
        rep(i,N){
            if(v[i].fi) continue;
            else ans=(ans*v[i].se)%MOD;
        }
        cout << ans << endl;
    }

}