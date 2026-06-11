#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}


const int mod = 1000000007;
int main() {
    int n;
    cin >> n;
    vector<int>cnt(1005);
    for(int i = 2;i<=n;i++) {
        int a = i;
        for(int j = 2;j*j<=n;j++) {
            if(a%j != 0) continue;
            int tmp = 0;
            while(a%j == 0) {
                a /= j;
                tmp++;
            }
            cnt[j] += tmp;
        }
        if(a != 1) cnt[a]++;
    }
    ll ans = 1;
    rep(i,1001) {
        if(cnt[i] > 0){
            ans *= cnt[i]+1;
            ans %= mod;
        }
    }
    cout << ans << endl;
}