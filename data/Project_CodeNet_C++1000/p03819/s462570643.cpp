#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B;
string S, T;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

int main() {
    class BIT{
            ll n;
      		vector<ll> bitree;
        public:
        	BIT(unsigned long _n) : bitree(_n + 1, 0){
              n = _n;
            }
        	void add(ll id, ll x){
              while(id <= n){
                bitree[id] += x;
                id += id & -id;
              }
              return;
            }
        	ll sum(ll id){
              ll temp = 0;
              while(id > 0){
                temp += bitree[id];
                id -= id & -id;
              }
              return temp;
            }
      };
    cin>>N>>M;
    vec l(N), r(N), ord(N);
    rep(i,N) cin>>l[i]>>r[i], ord[i] = i;
    BIT bit(M + 10);
    rep(i,N){
        bit.add(l[i], 1);
        bit.add(r[i] + 1, -1);
    }
    sort(ALL(ord), [&](int x, int y){
        return r[x] - l[x] > r[y] - l[y];
    });
    ord.push_back(0);
    vec ans(M);
    int buy = 0; //確定で購入
    Rreps(m, M + 1, 1){
        int id = ord[buy];
        while(buy != N && r[id] - l[id] >= m){
            bit.add(l[id], -1);
            bit.add(r[id] + 1, 1);
            ++buy;
            id = ord[buy];
        }
        //buy以外は、BITでの重複カウントはされない
        ans[m - 1] = buy;
        for(int j = m; j <= M; j += m) ans[m - 1] += bit.sum(j);
    }
    rep(i,M) cout<<ans[i]<<endl;
}