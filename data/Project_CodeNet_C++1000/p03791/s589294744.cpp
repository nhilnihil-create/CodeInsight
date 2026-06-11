#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
void read(int& x){ scanf("%d",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back

int n;
int a[100010];
int l[100010];

int main()
{
#ifdef NAMSEO
	freopen("in", "r", stdin);
#endif
	
    read(n);
    int lm = 0;
    const ll M=int(1e9)+7;
    ll ans = 1;
    for(int i=1; i<=n; ++i){
		read(a[i]);
		l[i] = lm;
		ans *= (i-lm);
		ans %= M;
		lm = max(lm, i - (a[i]+1)/2);
    }
    
    printf("%lld\n", ans);
    return 0;
}
