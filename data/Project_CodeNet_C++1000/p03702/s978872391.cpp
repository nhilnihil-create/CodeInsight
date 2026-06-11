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
ll INF = 1000000000000000;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;


ll N,A,B;
vector<ll> H(100010);

bool F(ll x){
    ll cnt = 0;
    rep(i,N){
        cnt += (max(H[i] - (B * x),(ll)0) + A-B-1) / (A-B);
    }
    return (x >= cnt);
}

int main(){
   cin >> N >> A >> B;
   rep(i,N) cin >> H[i];
   ll l = 0,r = 1000000010;
   while(r-l > 1){
       ll mid = (l+r)/2;
       if(F(mid)){
           r = mid;
       }else{
           l = mid;
       } 
   }
   cout << r << endl;
}

