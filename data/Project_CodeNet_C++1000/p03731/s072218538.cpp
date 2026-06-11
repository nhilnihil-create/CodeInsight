#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%lld",&x);
int main(){
    ll n, t;
    sc(n) sc(t)
    ll T[n], ans = 0;
    for (int i = 0; i < n; i++) sc(T[i])
    int now = T[0];
    for (int i = 1; i < n; i++){
        if (now + t <=  T[i]) ans += t;
        else ans += T[i] - now;
        now = T[i];
    }
    ans += t;
    cout << ans << endl;
    return 0;
}