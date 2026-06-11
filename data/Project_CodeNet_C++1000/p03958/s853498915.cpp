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
    int K,T;cin >> K >> T;
    vector<int> a(T);rep(i,T)cin >> a[i];
    sort(rall(a));
    int ma = a[0];
    int sum = -1 * a[0];
    rep(i,T)sum += a[i];

    if(ma-1 <= sum)cout << 0 << endl;
    else{
        cout << ma-1-sum << endl;
    }
}