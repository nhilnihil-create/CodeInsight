#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<deque>
#include<cassert>

using namespace std;

#define sz(x) (int)(x.size())
#define fi(a,b) for(int i=a;i<b;++i)
#define fj(a,b) for(int j=a;j<b;++j)
#define fo(a,b) for(int o=a;o<b;++o)
#define fdi(a,b) for(int i=a-1;i>=b;--i)
#define fdj(a,b) for(int j=a-1;j>=b;--j)
#define fdo(a,b) for(int o=a-1;o>=b;--o)
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;
/////////////////////////////////

int const N = 1e5 + 41;
int const M = 241;

int n, m;
int a[N];
int k, b[N];
vector<int> ansa, ansb;

void bad(){
	printf("Impossible\n");
	exit(0);
}

void solve(){
	if(m == 1){
		ansa.pb(a[0]);
		if(a[0] == 1){
			ansb.pb(1);
		}else{
			ansb.pb(a[0] - 1);
			ansb.pb(1);
		}
		return;
	}
	vector<int> o, e;
	fi(0, m) if(a[i] % 2 == 0) e.pb(a[i]);
	else o.pb(a[i]);
	if(sz(o) > 2) bad();
	if(sz(o)){
		ansa.pb(o[0]);
	}
	fi(0, sz(e)) ansa.pb(e[i]);
	if(sz(o) > 1) ansa.pb(o.back());
	ansb.pb(ansa[0] + 1);
	fi(1, sz(ansa)){
		ansb.pb(ansa[i]);
	}
	--ansb.back();
	if(ansb.back() == 0) ansb.pop_back();
}

int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	scanf("%d %d",&n,&m);
	fi(0, n) scanf("%d",&a[i]);

	solve();

	fi(0, sz(ansa)) printf("%d ",ansa[i]);
	printf("\n");
	printf("%d\n",sz(ansb));
	fi(0, sz(ansb)) printf("%d ",ansb[i]);

	return 0;
}