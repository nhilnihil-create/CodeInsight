#include <bits/stdc++.h>
using namespace std;

#define int long long
struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
using intpair = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((int)((a) + (b) - 1)/(int)(b))

const int MOD = 1e9 + 7;
inline int mod (int a, int m = MOD) { return (a % m + m) % m; }

signed main(){
    int n;
    string s, t;
    cin >> n >> s >> t;
    vector<int> dominoes;
    rep(i,n){
        if(s[i]==t[i]){
            dominoes.push_back(1);
        }else{
            dominoes.push_back(2);
            i++;
        }
    }
    int ans;
    if(dominoes[0] == 1){
        ans = 3;
    }else{
        ans = 6;
    }
    reps(i,1,dominoes.size()-1){
        if(dominoes[i] == 1){
            if(dominoes[i-1] == 1){
                ans = mod(ans * 2);
            }
        }else{
            if(dominoes[i-1] == 1){
                ans = mod(ans * 2);
            }else{
                ans = mod(ans * 3);
            }
        }
    }
    cout << ans << endl;
}