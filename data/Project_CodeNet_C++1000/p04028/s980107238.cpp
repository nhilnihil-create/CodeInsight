//pragma
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define REPP(i,a,b,d) for(int i=a;i<=b;i+=d)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,d) for(int i=a;i>=b;i-=d)
#define REV(i,a,b) REVV(i,a,b,1)

#define FOR(i,a) for(int i=0; i<a; i++)
#define FORD(i,a) for(int i=(int)a-1; i>=0; i--)

#define mp make_pair

#define pb push_back
#define F first
#define S second

const int OO = 1e9;
const ll INF = 1e18;

const int irand(int lo,int hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

const ll lrand(ll lo,ll hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

#define getc getchar
template<typename T>
T getnum(){
	int sign = 1;
	T ret = 0;
	char c;

	do{
		c = getc();
	}while(c == ' ' || c == '\n');
	if(c == '-')sign = -1;
	else ret = c-'0';
	while(1){
		c = getc();
		if(c < '0' || c > '9')break;
		ret = 10*ret + c-'0';
	}
	return sign * ret;
}

inline void ini(int& x){
	x = getnum<int>();
}

inline void scani(int& x){
	scanf("%d",&x);
}

//end of macro

const ll MOD = 1e9 + 7;

inline ll addmod(ll a, ll b){
    if(a+b<MOD)return a+b;
    return a+b-MOD;
}
inline ll submod(ll a, ll b){
    return addmod(a, MOD-b);
}
inline ll mulmod(ll a, ll b){
    return (a*b)%MOD;
}
inline ll expmod(ll a, ll e){
    ll ret = 1;
    while(e){
        if(e&1)ret = mulmod(ret, a);
        a = mulmod(a, a);
        e >>= 1;
    }
    return ret;
}
inline ll divmod(ll a, ll b){
    return mulmod(a, expmod(b, MOD-2));
}

const int N = 5005;

int n;
string str;

int memo[N][N];
int dp(int now, int left){
    if(left == 0)return (now==str.size()) ? 1 : 0;
    int& ret = memo[now][left];
    if(ret != -1)return ret;
    
    // advance
    ret = dp(now+1, left-1);
    
    // backspace
    if(now == 0)ret = addmod(ret, dp(now, left-1));
    else ret = addmod(ret, mulmod(2, dp(now-1, left-1)));
    
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #define endl '\n'
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(10);
    
    cin>>n>>str;
    memset(memo, -1, sizeof memo);
    cout << dp(0, n) << endl;
    
    return 0;
}