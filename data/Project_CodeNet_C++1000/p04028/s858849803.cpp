#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;
ll inv[10000100];
ll FactorialInv[10000100];
ll Factorial[10000100];
ll beki(ll a, ll b){
    a %= mod;
    if(b == 0){
        return 1;
    }
    ll ans = beki(a, b / 2);
    ans = ans * ans % mod;
    if(b % 2 == 1){
        ans = ans * a % mod;
    }
    return ans;
}
void init_combination(){
    const int MAX = 100002;
    Factorial[0] = 1;
    inv[0] = 1;
    for(int i = 1; i <= MAX; i++){
        Factorial[i] = Factorial[i - 1] * i % mod;
    }
    FactorialInv[MAX] = beki(Factorial[MAX], mod - 2);
    for(ll i = MAX - 1; i >= 0; i--) {
        FactorialInv[i] = FactorialInv[i+1] * (i+1) % mod;
    }
    for(int i = 1; i <= MAX; i++) {
        inv[i] = FactorialInv[i] * Factorial[i-1] % mod;
    }
}
ll combination(ll a, ll b){
    if((a == b) || (b == 0)){
        return 1;
    }
    if(a < b) return 0;
    ll ans = Factorial[a] * FactorialInv[b] % mod;
    ans = ans * FactorialInv[a - b] % mod;
    return ans;
}

ll catalan[6000];
vector<ll> Zero;
vector<ll> Poly;
int N;
string S;

void print(vector<ll> &a) {
    for(auto tmp : a) cerr << tmp << " ";
    cerr << endl;
}



void mul(vector<ll> &a, vector<ll> &b) {
    vector<ll> C;
    C.resize(N + 1);
    for(int i = 0; i <= N; i++) C[i] = a[i];
    for(int j = N; j >= 0; j--) {
        for(int i = 0; i <= j; i++) {
            a[j] += a[j-i] * b[i];
            a[j] %= mod;
        }
    }
    for(int i = 0; i <= N; i++) {
        a[i] = (a[i] - C[i] + mod) % mod;
    }
    /*
    for(int i = 0; i <= N; i++) {
        for(int j = 0; i + j <= N; j++) {
            cerr << i << " " << j << endl;
            ret[i+j] += a[i] * b[j];
            ret[i+j] %= mod;
        }
    }
    for(int i = 0; i <= N; i++) {
        a[i] = ret[i];
    }
    cerr << a.size() << " " << b.size() << " " << ret.size() << endl;
    */
}

ll powtwo[6000];

int main() {
    init_combination();
    cin >> N >> S;
    Zero.resize(N + 1);
    powtwo[0] = 1;
    for(ll i = 1; i <= 5000; i++) {
        powtwo[i] = powtwo[i-1] * 2 % mod;
    }
    for(int i = 0; i < 5000; i++) {
        catalan[i] = combination(2 * i, i) * beki(i + 1, mod - 2) % mod;
    }
    //for(int i = 0; i <= 5; i++) cerr << i << " " << catalan[i] << endl;
    Zero[0] = 1;
    for(ll before = 0; before < N; before++) {
        Zero[before+1] += Zero[before];
        Zero[before+1] %= mod;
        for(int delta = 0; ; delta++) {
            ll to = before + 2 * delta + 2;
            if(to > N) break;
            ll factor = Zero[before] * catalan[delta] % mod;
            factor = factor * powtwo[delta+1] % mod;
            Zero[to] += factor;
            Zero[to] %= mod;
        }
    }
    Poly.resize(N + 1);
    for(ll delta = 0; ; delta++) {
        ll idx = 2 * delta + 1;
        if(idx > N) break;
        Poly[idx] = catalan[delta] * powtwo[delta] % mod;
    }
    int sz = S.size();
    //print(Zero);
    //print(Poly);
    for(int bits = 0; bits < 13; bits++) {
        if((1 << bits) & sz) {
            mul(Zero, Poly);
        }
        mul(Poly, Poly);
    }
    cout << Zero[N] << endl;
    return 0;
}