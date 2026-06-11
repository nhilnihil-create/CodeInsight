#include <bits/stdc++.h>
#define il inline
#define ri register int
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define mid ((l+r)>>1)
#define MAXN 100050
#define MAXM
#define MOD
#define INF (1<<25)
#define eps (1e-6)
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair <int, int> pii;
typedef pair <LL, int> pli;
typedef pair <int, LL> pil;
typedef pair <LL, LL> pll;
int n, a[MAXN];
int main() {
//	freopen("nim.in", "r", stdin);
//	freopen("nim.out", "w", stdout);
    scanf("%d", &n);
    for(ri i = 1; i <= n; ++i) scanf("%d", &a[i]), a[i] *= -1;
    sort(a+1, a+n+1);
    for(ri i = 1; i <= n; ++i) a[i] *= -1;
    int pos = 0;
    for(ri i = 1; i <= n; ++i) 
        if(a[i] >= i) pos = i;
    int ans = 0;
    if((a[pos]-pos) & 1) ans |= 1;
    int k = pos+1;
    while(a[k] == pos) ++k;
    --k;
    if(k >= pos && (k-pos) & 1) ans |= 1;
//  cout<<pos<<' '<<k<<endl;
    if(ans) cout<<"First\n";
    else cout<<"Second\n";
    return 0;
}