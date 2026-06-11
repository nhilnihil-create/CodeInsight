#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
const int INF = 1<<29;
//const int MODINF = 1000000007;
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, 0, N) cin >> a.at(i);
    int ans_f = INF;
    rep(i, -100, 101){
        int ans = 0;
        rep(j, 0, N) ans += pow(a.at(j) - i, 2);
        ans_f = min(ans, ans_f);
    }
    cout << ans_f << endl;
}