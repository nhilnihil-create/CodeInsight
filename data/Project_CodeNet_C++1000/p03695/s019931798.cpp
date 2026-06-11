// ░░░░░░░░( •̪●)░░░░░░░░░░░░░░░░░░░░░░░░
// ░░░░░░███████ ]▄▄▄▄▄▄▄▄▃░░░▃░░░░ ▃░
// ▂▄▅█████████▅▄▃▂░░░░░░░░░░░░░░░░░
// [███████████████████].░░░░░░░░░░░░░░
// ◥⊙▲⊙▲⊙▲⊙▲⊙▲⊙▲⊙◤...░░░░░░░░░░░░

//PointBlank's code (⌐■_■)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define repp(I, A, B) for(int I = A; I <= B; I++)
#define rep(I, A, B) for(int I = A; I < B; I++)
#define rrep(I, B, A) for(int I = B; I >= A; I--)
#define pb emplace_back
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define mem(A, B) memset(A, B, sizeof(A));
#define mem0(A) memset(A, 0, sizeof(A));
#define quickio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define in_edges(M) repp(I, 1, M){ll A, B; cin >> A >> B; v[A].pb(B), v[B].pb(A);}
#define in_edges2(M) repp(I, 1, M){ll A, B; cin >> A >> B; v[A].pb(B);}
#define endl "\n"
#define debug(this) cerr<<"> "<<#this<<" : "<<this<<"\n"
#define bitsf(n) __builtin_popcount(n)
ll power(ll x, ll y); 

const ll MOD = 1000000007;
 
int main() //PointBlank's code ¯\_(ツ)_/¯
{
    int n;
    cin >> n;
    set<int> st;
    int f = 0;
    rep(i, 0, n){
        int x;
        cin >> x;
        if(x > 0 && x < 400) st.insert(0);
        else if(x > 399 && x < 800) st.insert(1);
        else if(x > 799 && x < 1200) st.insert(2);
        else if(x > 1199 && x < 1600) st.insert(3);
        else if(x > 1599 && x < 2000) st.insert(4);
        else if(x > 1999 && x < 2400) st.insert(5);
        else if(x > 2399 && x < 2800) st.insert(6);
        else if(x > 2799 && x < 3200) st.insert(7);
        else f++;
    }
    int mn = st.size(), mx = st.size() + f;
    if(mn == 0) mn = 1;
    cout << mn << " " << mx;
}
 
ll power(ll x, ll y)
{ 
    ll res = 1; x %= MOD;
    while(y > 0){if(y & 1) res = (res*x) % MOD; y = y>>1, x = (x*x) % MOD;} 
    return res; 
}
