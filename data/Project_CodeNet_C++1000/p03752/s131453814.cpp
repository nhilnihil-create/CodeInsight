#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n)  for(int i=0;i<(n);++i)
#define REPr(i, n) for(int i=(n)-1;i>=0; --i)
#define FORq(i, m, n) for(int i = (m);i <= (n);++i)
#define FORqr(i, m, n) for(int i = (n);i >=(m);--i)
#define PB push_back
#define MP make_pair
#define DEBUG printf("%s\n","debug")
#define fst first
#define snd second
#define SIN(x, S) (S.count(x) != 0)
#define M0(x) memset(x,0,sizeof(x))
#define FILL(x, y) memset(x,y,sizeof(x))
#define MM(x) memset(x,-1,sizeof(x))
#define ALL(x) (x).begin(),(x).end()
#define SCD(n) scanf("%d",&n)
#define SCD2(m,n) scanf("%d%d",&m,&n)
#define SCD3(m,n,k) scanf("%d%d%d",&m,&n,&k)
#define SCLLD(n) scanf("%lld",&n)
#define SCLLD2(m,n) scanf("%lld%lld",&m,&n)
#define SCLLD3(m,n,k) scanf("%lld%lld%lld",&m,&n,&k)
using namespace std;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef long long ll;
typedef long long integer;
///////////////////////////////////////////////
const ll MOD = 1e9+7;

ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }

template<class T>
inline bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<class T>
inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
///////////////////////////////////////////////
/*(._.)*/
int main(){
	int N; cin >> N;
	int K; cin >> K;
	vector<ll> B(N);
	REP(i,N){
	    cin >> B[i];
	}

	ll ans = 1e15;

	for (int b = 0; b < (1<<N); b++){
		if (__builtin_popcount(b) != K) continue;
		vector<ll> A;
		A = B;
		ll nowH = A[0];
		ll nowc = 0;
		REP(i,N){ //bit loop
			if (i == 0) continue;
			if (b & (1<<i)){ //i-th digit(bitにi-thのフラグが立っているかどうか)
				if (nowH >= A[i]){
					nowc += nowH - A[i] + 1;
					A[i] = nowH + 1;
					nowH = A[i];
				}else{
					nowH = A[i];
				}
			}else{
				if (nowH <= A[i]){
					//nowc += nowH - A[i] + 1;
					//A[i] = nowH + 1;
					nowH = A[i];
				}
			}
		}

		//cout << nowc << " (bit = " << b << ")" << "\n";
		chmin(ans,nowc);
	}

	cout << ans << "\n";

	return 0;
}
