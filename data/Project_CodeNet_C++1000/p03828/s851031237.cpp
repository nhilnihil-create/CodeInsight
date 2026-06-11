#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <numeric>
#include <algorithm>
#include <tuple>
#include <stdio.h>
#include <bitset>
#include <limits.h>
#include <complex>
#include <deque>
#include <iomanip>
#include <list>
#include <cstring>
using namespace std;
#define pi pair<int,int>
#define pl pair<long long,long long>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define en cout << endl //セミコロンつけろ
//#define MM 1000000000
//#define MOD MM+7
typedef long long ll;
//const int MM = 1e9;
const int MOD = 1e9+7;
const long double PI = acos(-1);
const long long INF = 1e15;
int dx[8] = {-1,0,1,0,-1,-1,1,1};
int dy[8] = {0,-1,0,1,-1,1,1,-1};
// 'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122
// priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > pq;

template<typename T> //最大公約数
T GCD(T u,T v){
    return v ? GCD(v,u%v) : u;
}
template<typename T> //最小公倍数
T LCM(T x,T y){
    T gc = GCD(x,y);
    return x*y/gc;
}

const int COM_MAX = 500500;
long long fac[COM_MAX],finv[COM_MAX],inv[COM_MAX];
void init(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < COM_MAX; i++){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = MOD - inv[MOD%i]*(MOD/i)%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}

long long COM(int n,int k){
    if(n < k || n < 0 || k < 0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}


// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod を計算する
long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}

template<typename T> 
struct RUQ
{
    // pos は全体のノードを表す配列
    // lazy は遅延評価を行うための配列
    vector< T > pos, lazy; 
    int maxLimit;
    const ll MAXRUQ = 2147483647; // 2^31-1

    void Init(int _n){
        int limit = 1;
        while (limit < _n){
            limit *= 2;
        }
        maxLimit = limit;
        pos.assign(limit * 2 + 1, MAXRUQ);
        lazy.assign(limit*2 + 1, MAXRUQ);
    }

    void Evaluate(int k){
        if (lazy[k] == MAXRUQ) return;
        if (k < maxLimit - 1){
            lazy[k*2 + 1] = lazy[k];
            lazy[k*2 + 2] = lazy[k];
        }

        pos[k] = lazy[k];
        lazy[k] = MAXRUQ;
    }

    // Updateを用いれば十分
    void sub_Update(int a, int b, int x, int k, int left, int right){
        Evaluate(k);
        if (a <= left && right <= b){
            lazy[k] = x;
            Evaluate(k);
        } else if (a < right && left < b){
            sub_Update(a, b, x, k*2+1, left, (left+right) / 2);
            sub_Update(a, b, x, k*2+2, (left+right) / 2, right);
            pos[k] = min(pos[k*2+1], pos[k*2+2]);
        }
    }

    // 区間更新
    // [a, b) の値を x に更新する
    void Update(int a, int b, int x){
        sub_Update(a, b, x, 0, 0, maxLimit);
    }


    T sub_Query(int a, int b, int k, int left, int right){
        Evaluate(k);
        if (right <= a || b <= left){
            return MAXRUQ;
        } else if (a <= left && right <= b){
            return pos[k];
        } else {
            T vl = sub_Query(a, b, k*2+1, left, (right+left) / 2);
            T vr = sub_Query(a, b, k*2+2, (left+right) / 2, right);
            return min(vl, vr);
        }
    }

    T Query(int a, int b){
        return sub_Query(a, b, 0, 0, maxLimit);
    }
};

bool IsPrime(int x){
    for (int i = 2; i*i <= x; i++){
        if (x % i == 0){
            return false;
        }
    }
    return true;
}

vector<pair<int, int> > PrimeFactor(int N){
    vector<pair<int, int> > prime;
    for (int i = 2; i*i <= N; i++){
        if (N % i != 0) continue;
        int cnt = 0;
        while (N % i == 0){
            cnt++;
            N /= i;
        }
        prime.push_back({i, cnt});
    }
    if (N > 1){
        prime.push_back({N, 1});
    }
    return prime;
}

int main(){
    int N; cin >> N;
    vector<ll> primeCount(N+1, 0);
    for (int i = 2; i <= N; i++){
        vector<pair<int, int> > primefactor = PrimeFactor(i);
        for (auto p: primefactor){
            primeCount[p.first] += p.second;
        }
    }
    ll res = 1;
    for (int i = 2; i <= N; i++){
        //cout << primeCount[i]+1 << endl;
        res *= primeCount[i]+1;
        res %= MOD;
    }
    cout << res << endl;
}