#include <bits/stdc++.h>
#define pq priority_queue
#define P pair<int, int>
#define P2 pair<int, P>
#define P3 pair<int, P2>
using namespace std;
typedef long long ll; typedef long double ld;
constexpr int gcd(int a, int b){return b ? gcd(b, a % b) : a;}
constexpr int lcm(int a, int b){return a / gcd(a, b) * b;}
constexpr int INF = 1e9, MOD = INF + 7, around[] = {0, 1, 1, -1, -1, 0, -1, 1, 0, 0};
constexpr int inv(const int x, int n, const int mod){ll ret=1,pos=x;while(n){if(n&1)(ret*=pos)%=mod;(pos*=pos)%=mod;n>>=1;}return ret;}
template<int n> struct Factorial{ll arr[n+1],ary[n+1];constexpr Factorial():arr(),ary(){arr[0]=1;ary[0]=1;for(int i=0;i<n;i++){arr[i+1]=arr[i]*(i+1)%MOD;ary[i+1]=inv(arr[i+1],MOD-2,MOD);}}};
constexpr Factorial<10> fact;
constexpr int comb(int a, int b){ll pos = fact.arr[a], pot = fact.ary[a - b], por = fact.ary[b];return pos * pot % MOD * por % MOD;}
constexpr int vx[] = {1, 0, -1, 0}, vy[] = {0, 1, 0, -1};
constexpr int sqrtN = 512, logN = 32;
constexpr ld PI = abs(acos(-1));
constexpr ll LINF=1e18;

int main(){
	int n; cin >> n; int a[100010]; char b[100010]; cin >> a[0];
	for(int i = 1; i < n; i++) cin >> b[i] >> a[i];
	
	ll s = a[0];
	for(int i = 1; i < n; i++){
		if(b[i] == '+') s += a[i];
		else s -= a[i];
	}
	
	ll pos = 0, pot = 0, ma = s;
	for(int i = n - 1; i > 0; i--){
		if(b[i] == '+') pot += 2 * a[i];
		else{
			ma = max(ma, s + pos - pot);
			pos += 2 * a[i];
			pot = 0;
		}
	}
	
	cout << ma << endl;
	return 0;
}
