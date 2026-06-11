#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define per(i,a,b) for(int i = a; i >= b; i--)
#define __ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef double db;
const db EPS = 1e-9;
const int N = 2000+10;
using namespace std;

void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}

int st[2*N][25],n;
ll x,a[2*N],ans;

//数组范围为[0,len-1]
void init(){
    for(int i = 1; i <= 2*n; i++) st[i][0] = a[i];
    for(int j = 1; (1<<j) <= 2*n; j++){
        for(int i = 1; i + (1<<j) - 1 <= 2*n; i++)
            st[i][j] = min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    }
}

//求[l,r]之间的最小值
int query(int l,int r){
    int k = (int)(log((double)(r - l + 1)) / log(2.0));
    return min(st[l][k],st[r-(1<<k)+1][k]);
}


int main()
{
	scanf("%d%lld",&n,&x);
	rep(i,1,n) scanf("%lld",&a[i]);
	rep(i,n+1,2*n) a[i] = a[i-n];
 	init();
 	rep(i,1,n) ans += a[i];
 	rep(k,1,n){
 		ll tmp = (ll)k*x;
 		rep(i,1,n){
 			int x = i+n-k, y = i+n;
 			// logs(i,k,x,y);
 			tmp += query(x,y);
 		}
 		ans = min(ans,tmp);
 	}
 	printf("%lld\n",ans);
	return 0;
}