#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
typedef complex<double> xy_t;
const lint mod = 1e9 + 7;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int a[n];
    vector<int> v[m];
    rep(i, n) {
        scanf("%d", &a[i]);
        --a[i];
        if(i > 0) v[a[i]].push_back(i);
    }
    
    lint num[2*m];
    rep(i, 2*m) num[i] = 0;
    rep(i, n-1){
        if(a[i] < a[i+1]){
            ++num[a[i]+1];
            --num[a[i+1]];
        }
        else{
            ++num[a[i]+1];
            --num[a[i+1]+m];
        }
    }
    rep(i, 2*m-1) num[i+1] += num[i];
    rep(i, m) num[i] += num[i+m];
    
    lint cnt = 0;
    rep(i, n-1){
        lint dif = (a[i+1]-a[i]+m)%m * 1LL;
        if(((m-a[i])%m < dif && a[i+1] < dif) || a[i+1] == 0) cnt += 1+a[i+1] * 1LL;
        else cnt += dif;
    }
    
    lint ans = cnt;
    rep(i, m-1){
        for(int j: v[i]) cnt += (a[j]-a[j-1]+m)%m-1 * 1LL;
        cnt -= num[i];
        ans = min(ans, cnt);
    }
    
    printf("%lld\n", ans);
}