#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
#define ALL(a)  (a).begin(),(a).end()
const ll INF = 1e18+18;
const ll MAX = 200000;
const ll MOD = 1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
static const long double pi = 3.141592653589793;



int main(){
    ll N;
    cin>>N;
    map<ll, ll> M;
    set<ll> S;
    vector<ll> A(N);
    rep(i, N){
        cin>>A[i];
        M[A[i]]++;
        S.insert(A[i]);
    }
    ll Ans=0;
    while(!S.empty()){
        auto itr=S.begin();
        if(M[*itr]%2)Ans++;
        S.erase(itr);
    }
    cout<<Ans<<endl;
}
     