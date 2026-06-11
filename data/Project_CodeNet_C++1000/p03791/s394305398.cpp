#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

#define sz(x) (int)(x.size())
#define fi(a, b) for(int i=a;i<b;++i)
#define fj(a, b) for(int j=a;j<b;++j)
#define fk(a, b) for(int k=a;k<b;++k)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
////////////

int const MOD = 1e9 + 7;

int mul(int a, int b) {return a * 1LL * b % MOD;}

void add(int &a, int b) {a += b; if(a>=MOD) a-= MOD;}

void solve(){
	int ans = 1;
	int p = 1;

	int n;
	scanf("%d",&n);
	fi(0, n){
		int x;
		scanf("%d",&x);
		if(x < p){ 
			ans = mul(ans, (p+1)/2);
		}else{
			p += 2;
		}
	}

	int f = 1;
	for(int i=1;i*2+1<=p;++i){
		f = mul(f, i);
	}
	ans = mul(ans, f);



	printf("%d\n",ans);
}




int main(){
#ifdef _DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	solve();

	return 0;
}