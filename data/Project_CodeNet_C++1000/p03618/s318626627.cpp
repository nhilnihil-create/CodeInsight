#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

ll cnt[26];

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string s;
    cin >> s;
    int n = s.size();
    for(int i=0;i<n;i++){
        int x = s[i] - 'a';
        cnt[x]++;
    }
    ll ans = 1;
    for(int i=0;i<26;i++){
        if(cnt[i]){
            ans += ((n - cnt[i]) * cnt[i]);
        }
    }
    cout << ans/2 + 1  << endl;
}