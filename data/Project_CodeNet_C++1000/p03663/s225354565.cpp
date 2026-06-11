#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define fu(a,b,c) for(int a=b;a<=(int)c;++a)
#define fd(a,b,c) for(int a=b;a>=(int)c;--a)
#define cu(a,b,c) for(int a=b;a<(int)c;++a)
#define cd(a,b,c) for(int a=(b)-1;a>=(int)c;--a)
#define gcd(a,b) __gcd(a,b) 
#define pii pair<int,int>
#define pll pair<long long,long long>
#define all(a) a.begin(),a.end()
#define F first
#define S second
#define pb push_back
#define pf push_front
#define uint unsigned int
#define MOD 1000000007
#define MAXN 200005
#define MAXH 4
#define MAXM 100
#define INF 1LL << 60
#define ll long long
#define ull unsigned long long
#define RNG mt19937
#define udist(a,b) uniform_int_distribution<uint32_t> distribution(a,b)
#define max3(a,b,c) max(a, max(b, c))
#define min3(a,b,c) min(a, min(b, c))
#define gmax(a,b) a = max(a, b)
#define gmin(a,b) a = min(a, b)
#define whatis(x) cerr << #x << " is " << x << endl;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.1415926535897932384626433
using namespace std;
int cur[17];

bool ask(int l){
	printf("? ");
	cd(i,l,0)printf("%d",cur[i]);
	printf("\n");
	fflush(stdout);
	char c;
	scanf(" %c",&c);
	return c == 'Y';
}

int main(){
	// find len	
	int len = -1;
	fu(i,1,10){
		cur[i-1] = 1;
		if(!ask(i)){len = i-1;cur[i-1] = 0;break;}
		cur[i-1] = 0;
	}
	//whatis(len);
	if(len == -1){// power of ten
		int ans = -1;
		fu(i,1,10){
			cur[i-1] = 9;
			if(ask(i)){ans = i;break;}
		}
		printf("! ");
		printf("1");
		cu(i,0,ans-1)printf("0");
		printf("\n");
		fflush(stdout);
	}
	else{
		cd(i,17,17-len){
			int l = 1, r = 9;	
			int best = 0, m = 0;
			while(l <= r){
				m = l + (r-l)/2;	
				cur[i] = m;	
				if(!ask(17)){best = m;l = m + 1;}
				else r = m - 1;
			}
			cur[i] = best;
			cd(j,i,0)cur[j] = 9;
			bool res = ask(17);
			cd(j,i,0)cur[j] = 0;
			if(!res){
				cur[i] = best + 1;
				break;
			}
		}
		printf("! ");
		cd(i,17,17-len){
			printf("%d",cur[i]);
		}
		printf("\n");
		fflush(stdout);
	}
}
