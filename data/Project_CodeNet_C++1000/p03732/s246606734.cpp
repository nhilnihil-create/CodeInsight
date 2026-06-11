#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rrep(i, n) for (ll i = n - 1; i >= 0; i--)
#define Rep(i, r, n) for (ll i = r; i < n; i++)
#define RRep(i, r, n) for (ll i = n - 1; i <= r; i--)
#define debug(x) cout << #x << ' ' << '=' << ' ' << (x) << endl;
#define fs first
#define sc second
#define int long long
#define pb push_back
#define mp make_pair
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
const int MOD = (1000000007);
//const int MOD = (998244353);
//const int INF = (1 << 30)-1;
const int INF = (1LL << 60)-1;
const double EPS = (1 >> 30);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}

using Graph = vector<vector<pair<int, int>>>;
using Ki = vector<vector<int>>;
using Vi = vector<int>;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    //---------------------------------------------
    
    int N,W;
    cin>>N>>W;
    //vector<int> w(N);
    //vector<int> v(N);
    vector<vector<int>> w(4);
    int w1;
    rep(i,N){
        int we;
        int vi;
        cin>>we>>vi;
        if(i==0){
            w[0].pb(vi);
            w1=we;
        }
        else{
            w[we-w1].pb(vi);
        }
    }
    rep(i,4){
        sort(rall(w[i]));
        //debug(w[i].size());
    }
    ll ans=0;
    rep(i,w[0].size()+1){
        rep(j,w[1].size()+1){
            rep(k,w[2].size()+1){
                rep(l,w[3].size()+1){
                    if((i*w1+j*(w1+1)+k*(w1+2)+l*(w1+3))>W) continue;
                    //cout<<(i*w1+j*(w1+1)+k*(w1+2)+l*(w1+3))<<endl;
                    int memo=0;
                    rep(o,i){
                        memo+=w[0][o];
                    }
                    rep(op,j){
                        memo+=w[1][op];
                    }
                    rep(oq,k){
                        memo+=w[2][oq];
                    }
                    rep(oe,l){
                        memo+=w[3][oe];
                    }
                    ans=max(ans,memo);
                }
            }
        }
    }
    cout<<ans<<endl;
    
}