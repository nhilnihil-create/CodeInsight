#include <bits/stdc++.h>
using namespace std;

#define int long long
struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
const int MOD = 1e9 + 7;
using intpair = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((int)((a) + (b) - 1)/(int)(b))

void factor(map<int,int> &m, int num){
    for(int i=2; i*i <= num; i++){
        int p = 0;
        while(num%i==0){
            num /= i;
            p++;
        }
        if(p > 0){
            if(!m.count(i)) m[i] = 0;
            m.at(i) += p;
        }
    }
    if(num != 1){
        if(!m.count(num)) m[num] = 0;
        m.at(num)++;
    }
}

signed main() {
    int n; cin >> n;
    map<int,int> m;
    reps(i,1,n) factor(m, i);
    
    int ans = 1;
    for(auto p : m){
        ans = (ans * (p.second + 1)) % MOD;
    }
    
    cout << ans << endl;
}