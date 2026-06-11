#include <bits/stdc++.h>
#include <bitset>
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

int main(){
    cin>>N>>S;
    vector<bool> in(N), ans(N);
    rep(i,N) in[i] = S[i] == 'o';
    rep(s, 4){
        ans[0] = s%2;
        ans[1] = s/2;
        reps(i,2,N){
            ans[i] = ans[i-2] ^ ans[i-1] ^ in[i-1];
        }
        if(ans[0] ^ ans[1] ^ ans[N-1] == in[0]
        && ans[N-2] ^ ans[N-1] ^ ans[0] == in[N-1]){
            rep(i,N) cout<<(ans[i] ? 'S' : 'W');
            cout<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}