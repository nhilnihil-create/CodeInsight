#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main() {
    int N;cin >> N;
    vector<LL> A(N);
    rep(i,N)cin >> A[i];
    sort(all(A));
    vector<bool> ok(N+1);
    vector<LL> rui(N+1);
    rui[0] = 0;
    rep(i,N){
        rui[i+1] = rui[i] + A[i];
    }

    for(int i = 1;i <= N-1;i++){
        if(rui[i]*2 < A[i]){
            ok[i] = true;
        }
    }

    int num = 0;
    rep(i,N){
        if(ok[i])num = i;
    }
    cout << N - num << endl;
}