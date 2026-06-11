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
using ll=long long;
#define int ll
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define SZ(x) x.size()
#define fi first
#define se second
const int INF = 1e13;
using namespace std;

template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;

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

    int N,K; cin >> N >> K;
    int A[N]; rep(i,N) cin >> A[i];
    if(K==1) {
        cout << 0 << endl;
        return 0;
    }
    int ans=INF;
    int comb=(1<<(K-1))-1;
    while(comb < (1<<N)){
        if(comb&1);
        else{
            int now=0;
            int pos=0;
            rep(i,N){
                if(chmax(now,A[i]));
                else if((comb>>i)&1){
                    if(now+1>A[i]) {
                        pos+=now+1-A[i];
                        now++;
                    }
                }
            }
            chmin(ans,pos);
        }
        int x=comb&-comb,y=comb+x;
        comb=((comb&~y)/x>>1)|y;
    }
    cout << ans << endl;
}
