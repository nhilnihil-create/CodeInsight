#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
using namespace std;
 
#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592
 
const double EPS = 1e-10;
 
using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;
ll modpow(ll a, ll n, ll m){
    if(n == 0) return 1;
    ll half = modpow(a,n/2,m);
    ll res = half * half % m;
    if(n & 1) res = res * (a%m) % m;
    return res;
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> cnt(n);
    rep(i,n) cnt[a[i]]++;
    if(n % 2 == 0){
        for(int i = 1; i < n; i+=2){
            if(cnt[i] != 2){
                cout << 0 << endl;
                return 0;
            }
        }
    }
    else{
        if(cnt[0] != 1){
            cout << 0 << endl;
            return 0;
        }
        for(int i = 2; i < n; i+=2){
            if(cnt[i] != 2){
                cout << 0 << endl;
                return 0;
            }
        }
    }
    cout << modpow(2,n/2,MOD) << endl;
}