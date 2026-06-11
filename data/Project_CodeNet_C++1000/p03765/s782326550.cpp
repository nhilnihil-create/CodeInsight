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
#define MOD 1000000007
#define MAXN 205
#define MAXH 20
#define MAXM 52
#define INF 1LL << 30
#define ll long long
#define ull unsigned long long
#define RNG rng mt19937(time(NULL))
#define udist(a,b) uniform_int_distribution<uint32_t> distribution(a,b)
#define max3(a,b,c) max(a, max(b, c))
#define min3(a,b,c) min(a, min(b, c))
#define gmax(a,b) a = max(a, b)
#define gmin(a,b) a = min(a, b)
#define whatis(x) cerr << #x << " is " << x << endl;
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define PI 3.1415926535897932384626433
using namespace std;

int main(){
	fast_io();
	string s[2];
	cin >> s[0] >> s[1];
	int rsum[max(s[0].length(),s[1].length()) + 1][2][2] = {};
	cu(i,0,2){
		cu(j,0,2){
			cu(k,0,s[i].length()){
				rsum[k+1][j][i] = rsum[k][j][i] + (s[i][k] == ('A' + j));
			}
		}
	}
	int q;
	cin >> q;
	int x,y,l,r;
	while(q--){
		cin >> x >> y >> l >> r;	
		int a1 = (rsum[y][0][0] - rsum[x-1][0][0]) % 3;
		int b1 = (rsum[y][1][0] - rsum[x-1][1][0]) % 3;
		int a2 = (rsum[r][0][1] - rsum[l-1][0][1]) % 3;
		int b2 = (rsum[r][1][1] - rsum[l-1][1][1]) % 3;
		bool ans = (b1 - a1 + 3) % 3 == (b2 - a2 + 3) % 3;
		cout << (ans?"YES":"NO") << '\n';
	}
}
