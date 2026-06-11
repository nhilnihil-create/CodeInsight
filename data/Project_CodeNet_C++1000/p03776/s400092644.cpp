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
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    lint v[n];
    rep(i, n) scanf("%lld", &v[i]);
    sort(v, v+n, greater<lint>());
    
    double sum = 0;
    rep(i, a) sum += v[i];
    printf("%.10lf\n", 1.0 * sum / a);
    
    lint C[51][51];
    C[0][0] = 1;
    For(i, 1, 51){
        C[i][0] = C[i][i] = 1;
        For(j, 1, i) C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
    
    int num = 0;
    int num2 = 0;
    int num3 = 0;
    rep(i, n){
        if(v[i] > v[a-1]) ++num3;
        if(v[i] == v[a-1]) ++num2;
        if(v[i] == v[0]) ++num;
    }
    if(num <= a){
        printf("%lld\n", C[num2][a-num3]);
        return 0;
    }
    
    lint ans = 0;
    For(i, a, min(b, num)+1) ans += C[num][i];
    
    printf("%lld\n", ans);
}