#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, j, n) for (int i = j; i < (int)(n); i++)
#define brep(i, n) for (int i = n; i > 0; i--)
#define BREP(i, j, n) for(int i = n; i > j; i--)
#define TEST cout << "PASS" << endl
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9 + 1e6 + 1e3 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int main(){
    int n;
    cin >> n;
    ll S[100000];
    ll a[100000];
    rep(i, n) cin >> a[i];
    S[0] = a[0];
    //+-+-の順
    ll ans = 0;
    if(S[0] <= 0) {
        ans -= S[0] - 1;
        S[0] = 1;
    }
    for(int i = 1; i < n; i++){
        S[i] = S[i-1] + a[i];
        if(i % 2 == 1&& S[i] >= 0){//偶数：-にする
            ans += S[i] + 1;
            S[i] = -1;
        }
        if(i % 2 == 0 && S[i] <= 0){//奇数：+にする
            ans -= S[i] - 1;
            S[i] = 1;
        }
    }
    ll tmp = ans;
    S[0] = a[0];
    //-+-+の順
    ans = 0;
    if(S[0] >= 0){
        ans += S[0] + 1;
        S[0] = -1;
    }
    for(int i = 1; i < n; i++){
        S[i] = S[i-1] + a[i];
        if(i % 2 == 1&& S[i] <= 0){//偶数：+にする
            ans -= S[i] - 1;
            S[i] = 1;
        }
        if(i % 2 == 0 && S[i] >= 0){//奇数：-にする
            ans += S[i] + 1;
            S[i] = -1;
        }
    }
    cout << min(ans, tmp) << endl;
}