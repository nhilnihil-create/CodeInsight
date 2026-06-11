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
using namespace std;

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout<<fixed<<setprecision(20);

    int N,T; cin >> N >> T;
    vi A[4];
    int ww;
    rep(i,N){
        int a,b; cin >> a >> b;
        if(!i) ww = a;
        A[a-ww].eb(b);
    }
    rep(i,4){
        sort(all(A[i]),greater<int>());
    }
    int ans=0;
    rep(i,A[0].size()+1){
        rep(j,A[1].size()+1){
            rep(k,A[2].size()+1){
                rep(l,A[3].size()+1){
                    if(ww*i+(ww+1)*j+(ww+2)*k+(ww+3)*l > T) continue;
                    else {
                        int pos=0;
                        rep(n,i) pos+=A[0][n];
                        rep(m,j) pos+=A[1][m];
                        rep(o,k) pos+=A[2][o];
                        rep(p,l) pos+=A[3][p];
                        ans=max(ans,pos);
                    }
                }
            }
        }
    }

    cout << ans << endl;

}