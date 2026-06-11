#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;
#define MAXA 1001
#define MAXB 1001
#define MAXH 1000000001
#define MAXW 1000000007
#define INF 1000000007
#define MAXN 1001
#define MAXM 1001
#define MAXP 1000001
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;

int N, M;
int prime[MAXN];

ll prime_factorial_cnt(ll n, ll p){
    ll res = 0, pd = p;
    while(n >= p){
        res = res + n / p;
        p *= pd;
    }

    return res;
}

vector<ll> prime_vec(int n){
    vector<ll> res;
    for(int i = 2;i <= n;i++){
        if(prime[i] == 0){
            res.push_back(i);
            for(int j = i;j <= n;j += i){
                prime[j] = 1;
            }
        }
    }

    return res;
}

int main(){
    cin >> N;
    vector<ll> vec = prime_vec(N);
    vector<ll> cnt(MAXN, 0);

    for(int i = 0;i < vec.size();i++){
        cnt[i] = prime_factorial_cnt(N, vec[i]);
    }

    ll ans = 1;
    for(int i = 0;i < vec.size();i++){
        ans = (ans * (cnt[i] + 1)) % MOD;
    }

    printf("%lld\n", ans);
}