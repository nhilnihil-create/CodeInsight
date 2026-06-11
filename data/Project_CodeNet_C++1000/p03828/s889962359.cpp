#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<ll, ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

map<ll,ll> mp;

// 約数列挙関数
vector<ll> enum_divisors(ll n){

    vector<ll> res;
    for(ll i = 1; i*i <= n; i++){
        if(n%i==0){
            res.push_back(i);
            // 重複しない場合には加える
            if(n/i != i) res.push_back(n/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

vector<ll> makePrimeList(const ll &n){

    if(n <= 1){
        vector<ll> null;
        return null;
    }

    vector<ll> prime_list(1,2);
    for(ll i = 2; i <= n; i++){
        bool is_prime = true;
        for(ll j = 0; j < prime_list.size(); j++){
            ll now_prime = prime_list[j];
            if(i%now_prime==0){
                is_prime = false;
                break;
            }else if(now_prime*now_prime > n){
                break;
            }
        }
        if(is_prime){
            prime_list.push_back(i);
        }
    }
    return prime_list;
}

void factorization(const ll &n, const vector<ll> prime_list){
    // nの素因数分解をしたvectorを返す．
    // 少なくともnまでの素数を含むprime_listを渡す

    // vector<P> res;
    ll now = n;
    ll i = 0;
    while(now!=1){
        P p;
        p.first = prime_list[i];
        p.second = 0;
        while(now%p.first==0){
            p.second++;
            now /= p.first;
        }
        if(p.second!=0){
            mp[p.first]+=p.second;
        }
        i++;
    }

    return;
}

int main(){
    ll n; cin >> n;
    vector<ll> prim_list = makePrimeList(n);

    for(ll i = 1; i <= n; i++){
        factorization(i, prim_list);
    }
    
    ll ans = 1;
    ll mod = 1e9+7;
    for(auto it : mp){
        ans*=(it.second+1);
        ans=ans%mod;
    }
    cout << ans << endl;
    return 0;
}