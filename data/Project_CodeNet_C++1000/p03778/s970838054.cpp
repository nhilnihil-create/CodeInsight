#include <bits/stdc++.h>
using namespace std;

#define int long long
struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
using intpair = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()

signed main(){
    int w, a, b;
    cin >> w >> a >> b;
    if(a + w < b){
        cout << b - (a + w) << endl;
    }else if(b + w < a){
        cout << a - (b + w) << endl;
    }else{
        cout << 0 << endl;
    }
}