#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
ll MOD = 1000000007;
//ll INF = 21474836470000000;
ll INF = 100100100100100100;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N),B(N);
    rep(i,N){
        cin >> A[i];
        A[i]--;
        B[A[i]] = i;
    }
    set<ll> st;
    ll ans = 0;
    rep(i,N){
        ll x = B[i];
        ll l = -1,r = N;
        st.insert(x);
        auto itr = st.find(x);
        if(itr != st.begin()){
            itr--;
            l = *itr;
            itr++;
        }
        itr++;
        if(itr != st.end()){
            r = *itr;
        }
        ans += (i+1) * (r - x) * (x - l);
    }
    cout << ans << endl;
}