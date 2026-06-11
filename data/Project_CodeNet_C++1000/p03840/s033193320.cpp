#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
#define P(a,b) make_pair(a,b);
ll MOD = 1000000007;
//ll INF = 21474836470000000;
ll INF = 1001001001001001001;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<pair<ll,ll>>>;

ll A[10];

int main(){
    rep(i,7) cin >> A[i];
    ll I = A[0],L = A[3],J = A[4],ans = I + L + J;
    if(J > L) swap(J,L);
    if(I % 2 == 1){
        if(L % 2 == 1 && J % 2 == 1) ans = I + L + J;
        if(L % 2 == 0 && J % 2 == 0) ans--;
        if((L % 2) ^ (J % 2) == 1){
            if(L == 0 || J == 0) ans -= 2;
            else ans--;
        }
    }else{
        if(I == 0){
            if(L % 2 == 1 && J % 2 == 1) ans -= 2;
            if(L % 2 == 0 && J % 2 == 0) ans = I + L + J;
            if((L % 2) ^ (J % 2) == 1) ans--;
        }else{
            if(L % 2 == 1 && J % 2 == 1) ans--;
            if(L % 2 == 0 && J % 2 == 0) ans = I + L + J;
            if((L % 2) ^ (J % 2) == 1) ans--;
        }
    }
    cout << ans + A[1] << endl;
}
