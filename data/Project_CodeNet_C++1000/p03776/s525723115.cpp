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
long double EPS = 1;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

ll con(ll n,ll r){
    if(r > n) return 0;
    ll res = 1;
    ll b = 1;
    FOR(i,n-r+1,n+1){
        res *= i;
        if(res % b == 0 && b <= r){
            res /= b;
            b++;
        }
    }
    return res;
}

int main(){
    ll N,A,B;
    cin >> N >> A >> B;
    vector<ll> V(N),sum(N+1);
    map<ll,ll> mp;
    rep(i,N){
        cin >> V[i];
        mp[V[i]]++;
    }
    sort(ALL(V));
    rep(i,N) sum[i+1] = V[i] + sum[i];
    ll num = 0,den = 1;
    rep(i,N) FOR(j,i+1,N+1){
        if(A <= j-i && j-i <= B && num * (j-i) < (sum[j]-sum[i]) * den){
            num = sum[j] - sum[i];
            den = j-i;
        }
    }
    ll ans = 0;
    map<pair<ll,ll>,bool> mmpp;
    rep(i,N) FOR(j,i+1,N+1){
        if(A <= j-i && j-i <= B){
            if((sum[j]-sum[i]) * den == (j-i) * num){
                ll res = 1;
                map<ll,ll> MP;
                FOR(k,i,j){
                    MP[V[k]]++;
                }
                bool Q = 1;
                FOR(k,i,j){
                    if(V[k] != V[i]) Q = 0;
                }
                if(Q){
                    if(mmpp.count(make_pair(V[i],j-i))) continue;
                    else mmpp[make_pair(V[i],j-i)] = 1;
                }
                for(auto itr = MP.begin(); itr != MP.end();itr++){
                    ll key = itr -> first;
                    ll cnt = mp[key];
                    res *= con(cnt,MP[key]);
                }
                ans += res;
            }
        }
    }
    cout << setprecision(20) << fixed;
    cout << (double)num / den << endl;
    cout << ans << endl;
}
