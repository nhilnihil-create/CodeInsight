#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(long long i=0;i<(long long)(n);i++)
#define rep2(i, s, n) for(long long i=(s);i<(long long)(n);i++)
#define repi(i, n) for(int i=0;i<(int)(n);i++)
#define rep2i(i, s, n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(), v.end()

#define deg2rad(deg) (((deg)/360)*2*M_PI)
#define rad2deg(rad) (((rad)/2/M_PI)*360)

using ll = long long;
using ld = long double;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;

const ll INF = (1LL<<60);
const int INFi = (1<<29);

/*素数判定*/
bool is_prime(ll n){
    if(n==1) return false;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

/*約数列挙*/
vll enum_divisors(ll n){
    vll l;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            l.push_back(i);
            if(n/i != i) l.push_back(n/i);
        }
    }
   sort(all(l));
   return l;
}

/*素因数分解*/
vector<P> prime_factorize(ll n){
    vector<P> l;
    for(ll i=2;i*i<=n;i++){
        if(n%i!=0) continue;
        ll e = 0;
        while(n%i==0){
            e++;
            n /= i;
        }
        l.push_back({i, e});
    }
    if(n!=1) l.push_back({n, 1});
    return l;
}

/*最小公倍数*/
ll lcm(ll a, ll b){
    return a*b/__gcd(a,b);
}

/*最大公約数*/
ll gcd(ll a, ll b){
    return __gcd(a,b);
}

int main(){

    ll n, m; cin >> n >> m;
    vll to_1, to_n;
    ll a, b;
    rep(i, m){
        cin >> a >> b;
        if(a==1){
            to_1.push_back(b);
        }
        if(b==1){
            to_1.push_back(a);
        }
        if(a==n){
            to_n.push_back(b);
        }
        if(b==n){
            to_n.push_back(a);
        }
    }

    sort(all(to_1));
    sort(all(to_n));

    for(auto x:to_1){
        if(binary_search(all(to_n), x)){
            cout << "POSSIBLE" << endl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}