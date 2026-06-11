#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define rep(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define REP(i,num,n) for(ll i=num, i##_len=(n); i<i##_len; ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
const ll LLINF = 1LL<<60;
const int INTINF = 1<<30;
const int MOD = 1000000007;

void add(long long &a, long long b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};


long long com[51][51];

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    com[0][0] = 1;
    for (int i = 1; i < 51; ++i) {
        for (int j = 0; j <= i; ++j) {
            com[i][j] += com[i-1][j];
            if (j > 0) com[i][j] += com[i-1][j-1];        
        }
    }

    int N, A, B; cin >> N >> A >> B;
    vector<long long> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i];
    sort(v.begin(), v.end(), greater<long long>());

    // 最大値
    long long sum = 0;
    for (int i = 0; i < A; ++i) sum += v[i];
    double ave = (double)(sum) / A;

    // 小さいやつの個数
    long long res = 0;
    int num = 0;
    for (int i = 0; i < N; ++i) if (v[i] == v[A-1]) ++num;
    if (v[0] == v[A-1]) {
        for (int j = A; j <= B; ++j) {
            res += com[num][j];
        }
    }
    else {
        int a = 0;
        for (int i = 0; i < A; ++i) if (v[i] == v[A-1]) ++a;
        res = com[num][a];
    }
    cout << fixed << setprecision(10) << ave << endl;
    cout << res << endl;
}
