#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define fi(a,b) for(int i=a;i<b;++i)
#define fj(a,b) for(int j=a;j<b;++j)
#define fo(a,b) for(int o=a;o<b;++o)
typedef long long ll;
/////////////////////

int const N = 341;

int w[N][N], d[N][N], n;
ll ans;

void bad(){
	printf("-1\n");
	exit(0);
}

void solve(){
	memcpy(d, w, sizeof(w));
	fo(0, n){
		fi(0, n){
			fj(0, n){
				d[i][j] = min(d[i][j], d[i][o] + d[o][j]);
			}
		}
	}
	fi(0, n) fj(0, n) if(d[i][j] != w[i][j]) bad();
	fi(0, n) fj(i+1, n) ans += d[i][j];
	fi(0, n) fj(i+1, n){
		bool f = true;
		fo(0, n){
			if(o == i || o == j) continue;
			if(d[i][j] == d[i][o] + d[o][j]){
				f = false;
			}
		}
		if(!f) ans -= d[i][j];
	}
}

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	scanf("%d",&n);
	fi(0, n) fj(0, n) scanf("%d",&w[i][j]);

	solve();

	printf("%lld\n",ans);

	return 0;
}