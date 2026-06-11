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

int f(int n){
    if(n % 2 == 0){
        return n/2 * 11;
    }else{
        return f(n-1) + 6;
    }
}

signed main() {
    int x; cin >> x;
    int n = (x/11) * 2;
    while(f(n) < x) n++;
    cout << n << endl;
}