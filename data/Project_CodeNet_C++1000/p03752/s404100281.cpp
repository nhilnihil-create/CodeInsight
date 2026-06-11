 #include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <cassert>
#include <climits>
 #include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <cassert>
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
#include <unordered_set>
#pragma GCC optimize('Ofast')
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<ll> > vvll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define irep(it, stl) for(auto it = stl.begin(); it != stl.end(); it++)
#define drep(i,n) for(int i = (n) - 1; i >= 0; --i)
#define fin(ans) cout << (ans) << endl
#define mp(p,q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
struct io{io(){ios::sync_with_stdio(false);cin.tie(0);}};
const int INF = INT_MAX;
const ll LLINF = 1LL<<60;
const ll MOD = 1000000007;
const double EPS = 1e-9;
int main(void) {
    ll N,K;
    cin >> N >> K;
    vll A(N),Max(N+1);//maxは例えば３なら２までのmaxが入る
    int m = -1;
    rep(i,N){ 
        cin >> A[i];
        Max[i+1] = A[i];//まずは普通に高さを入れるだけ
        };
    rep(i,N) {
        Max[i+1] = max(Max[i+1],Max[i]);//直前までのmaxを入れる
    }
    
    ll value=LLINF;
    rep(bit,1<<N){
        //操作するidxを保管
        vll idxs;
        rep(i,N){
            if(bit&1<<i){
                idxs.push_back(i);
            }
        }

        if(idxs.size() != K) continue;
        ll maxH = 0 ,res=0;
        rep(i,K){
            maxH = max(maxH,Max[idxs[i]]);

            if(A[idxs[i]] <= maxH){
                //ここで操作するidxをそのidxまでのmax+1としてmaxH++、resはどれだけお金を費やしたか
                maxH++;
                res += maxH - A[idxs[i]];
            }else{
                maxH = A[idxs[i]];
            }
        }

        value = min(value,res);



    }
    fin(value);

}


