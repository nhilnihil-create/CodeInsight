#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e5 + 123, mod = (int)1e9 + 7, inf = (int)1e9, LOG = 60;


ll n, m, k;
ll x[N], ans[N], a[N];
                        
int dpl[N], upl[N][LOG];
int dpr[N], upr[N][LOG];

int main(){
	srand(time(0));
    scanf("%lld", &n);       
    for(int i = 1; i <= n; i++){
    	scanf("%lld", &x[i]);
    }
    scanf("%lld%lld", &m, &k);
    for(int i = 1; i <= m; i++){
    	scanf("%lld", &a[i]);
    }

    for(int i = 1; i <= n; i++)
    	dpl[i] = dpr[i] = i;

    for(int i = 1; i <= m; i++){
    	int p = a[i];  
    	swap(dpl[p], dpl[p + 1]);
    	swap(dpr[p], dpr[p - 1]);
    }
    
    for(int i = 1;i <= n; i++)
    	upl[dpl[i]][0] = i;
    for(int i = 1; i < LOG; i++)
    	for(int j = 1; j <= n; j++)
    		upl[j][i] = upl[ upl[j][i - 1] ][i - 1];
	
	for(int i = 1;i <= n; i++)
    	upr[dpr[i]][0] = i;
    for(int i = 1; i < LOG; i++)
    	for(int j = 1; j <= n; j++)
    		upr[j][i] = upr[ upr[j][i - 1] ][i - 1];

    for(int i = 1; i <= n; i++){
    	int l = i, r = i;

    	for(int j = 0; j < LOG; j++)
    		if((1ll<<j) & k)
    			l = upl[l][j], r = upr[r][j];

    	ans[l] += x[i];
    	ans[r + 1] -= x[i];
    }

	for(int i = 1; i <= n; i++)
		printf("%lld\n", (ans[i] += ans[i - 1]));

	return 0;
}