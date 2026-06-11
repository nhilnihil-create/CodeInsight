#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    int N;
    cin >> N;
    int a[N];
    rep(i, N) cin >> a[i];
    sort(a, a+N, greater<int>());
    bool ans = true;
    //直径
    int R = a[0];
    if(a[N-1] != (R+1)/2) ans = false;
    //num[i]:=最も遠い点との距離がiである点の数
    int num[R+1];
    fill(num, num+R+1, 0);
    rep(i, N) num[a[i]]++;
    rep3(i, R, R/2+1){
        if(num[i] < 2) ans = false;
    }
    if(R%2 == 0){
        if(num[R/2] != 1) ans = false;
    }
    else{
        if(num[(R+1)/2] != 2) ans = false;
    }
    if(ans) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}