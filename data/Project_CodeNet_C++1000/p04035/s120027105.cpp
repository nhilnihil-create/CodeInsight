#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair<ll, ll>
#define F first
#define S second
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main(){
    int N,L;cin >> N >> L;
    vector<int> a(N);rep(i,N)cin >> a[i];

    bool ok = false;
    int num = -1;
    rep(i,N-1){
        if(a[i]+a[i+1] >= L){
            num = i;
            ok = true;
            break;
        }
    }

    if(!ok){
        cout << "Impossible" << endl;
    }
    else{
        cout << "Possible" << endl;
        rep(i,num)cout << i+1 << endl;
        for(int i = N-1;i >= num + 2;i--)cout << i << endl;
        cout << num + 1 << endl;
    }
}
