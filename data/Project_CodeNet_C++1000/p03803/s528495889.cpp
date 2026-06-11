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

int f[] = {0,1000,2,3,4,5,6,7,8,9,10,11,12,13};

signed main() {
    int a, b;
    cin >> a >> b;
    if(f[a] > f[b]){
        cout << "Alice" << endl;
    }else if(f[a] < f[b]){
        cout << "Bob" << endl;
    }else{
        cout << "Draw" << endl;
    }
}