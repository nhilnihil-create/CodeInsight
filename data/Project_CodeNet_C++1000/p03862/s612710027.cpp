#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1 LL << 60
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
    LL N,x;cin >> N >> x;
    vector<LL> a(N);
    rep(i,N)cin >> a[i];
    LL ct = 0;

    rep(i,N-1){
        if(a[i] > x){
            LL t  = a[i] - x;
            ct += t;
            a[i] = x;
        }
        LL tmp = a[i] + a[i+1];
        if(tmp > x){
            LL t2 = tmp - x;
            ct += t2;
            a[i+1] = a[i+1] - t2;
        }
    }

    cout << ct << endl;
}