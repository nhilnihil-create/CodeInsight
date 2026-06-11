#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976

int main()
{
    int h,w; cin >> h >> w;
    int n = 26;
    char f[h][w]; 
    rep(i,h) rep(j,w) cin >> f[i][j];
    int cnt[n];
    rep(i,n) cnt[i] = 0;
    rep(i,h) rep(j,w) cnt[f[i][j]-'a']++;
    bool ans = true;
    int a = (h/2) * (w/2),c = (h%2) * (w%2);
    int b = ((h*w) - a * 4 - c)/2;
    rep(i,n){
        while(cnt[i] >= 4 && a > 0){
            cnt[i] -= 4;
            a--;
        }
    }
    rep(i,n){
        while(cnt[i] >= 2 && b > 0){
            cnt[i] -= 2;
            b--;
        }
    }
    rep(i,n){
        while(cnt[i] >= 1 && c > 0){
            cnt[i] -= 1;
            c--;
        }
    }
    if(a == 0 && b == 0 && c == 0) cout << "Yes";
    else cout << "No";
}