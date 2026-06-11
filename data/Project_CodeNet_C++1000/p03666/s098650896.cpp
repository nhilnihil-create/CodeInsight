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

ll N,M,H,W,K,Q,A,B,L,R;
string S, T;
const ll MOD = 998244353;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

int main() {
    ll C, D;
    cin>>N>>A>>B>>C>>D;
    --N;
    ll dif = abs(A - B), range = N * (D - C);
    bool yes = false;
    rep(i, N+1){
        ll temp = C*i - (N - i) * D;
        if(temp <= dif && temp + range >= dif) yes = true;
    }
    cout<<(yes ? "YES" : "NO")<<endl;
}
