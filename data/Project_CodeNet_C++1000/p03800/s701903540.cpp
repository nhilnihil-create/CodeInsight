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
	int n;
	string s;
	cin >> n >> s;
	int a[n] = {};
	cu(i,0,4){
		a[0] = i&1;
		a[1] = i >= 2;
		cu(j,2,n){
			a[j] = a[j - 1] ^ (s[j-1] == 'x') ^ a[j - 2];
		}
		if(a[0] == (a[n - 1] ^ (s[n-1] == 'x') ^ a[n - 2]) && a[1] == (a[0] ^ (s[0] == 'x') ^ a[n - 1])){
			cu(j,0,n){
				cout << (a[j]?'W':'S');
			}
			cout << '\n';
			return 0;
		}
	}
	cout << "-1" << '\n';
}
