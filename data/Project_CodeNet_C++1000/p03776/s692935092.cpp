#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
#define INF 1LL<<60

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

void comb(vector<vector <long long int> > &v){
  for(int i = 0;i <v.size(); i++){
    v[i][0]=1;
    v[i][i]=1;
  }
  for(int k = 1;k <v.size();k++){
    for(int j = 1;j<k;j++){
      v[k][j]=(v[k-1][j-1]+v[k-1][j]);
    }
  }
}


int main() {
    // COMinit();

    ll N, A, B;
    cin >> N >> A >> B;
    vector<ll> v(N);
    set<ll> unique;
    map<ll, int> num;
    REP(i, N) {
        ll tmp;
        cin >> tmp;
        unique.insert(tmp);
        num[tmp]++;
    }

    vector<vector<long long int> > combination(N+1,vector<long long int>(N+1,0));
    comb(combination);

    ll mean, combs;
    int flexible = 0;
    vector<ll> candidates;
    for(auto itr = unique.rbegin(); itr != unique.rend(); ++itr) {
        if(num[*itr] >= A) {
            break;
        } else {
            A -= num[*itr];
            B -= num[*itr];
            candidates.push_back(num[*itr]);
        }
        flexible++;
    }

    if(flexible == 0) {
        auto itr = unique.rbegin();
        double mean = *itr;
        ll combs = 0;
        for(int i=A; i<=B; i++) {
            combs += combination[num[*itr]][i];
        }
        printf("%.3f\n", mean);
        cout << combs << endl;
        return 0;
    }

    ll sum = 0;
    combs = 1;
    double denom = 0;
    auto itr = unique.rbegin();
    FOR(i, 0, flexible) {
        if(i < flexible) {
            sum += (*itr) * candidates[i];
            combs *= 1;
            denom += candidates[i];
        } else {
            sum += (*itr) * A;
            // combs *= COM(num[*itr], A);
            combs *= combination[num[*itr]][A];
            denom += A;
        }
        ++itr;
    }

    printf("%.6f\n", sum / denom);
     cout << combs << endl;

   return 0;
}