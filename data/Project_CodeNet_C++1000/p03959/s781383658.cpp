#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define LINF 1e18
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const double PI = acos(-1.0);
const double EPS = 1e-10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<ll> t(N),a(N);
    REP(i,N) cin>>t[i];
    REP(i,N) cin>>a[i];
    if(a[0]!=t[N-1]){
        cout<<0<<endl;
        return 0;
    }
    ll ans = 1;
    for(int i = 1; i < N-1; i++){
		if(t[i] == t[i-1] && a[i] == a[i+1]){
			ans *= min(t[i],a[i]);
			ans %= MOD;
		}else if(t[i] > t[i-1] && a[i] == a[i+1] && a[i] < t[i]){  //h[i] == t[i]
			ans = 0;
		}else if(t[i] == t[i-1] && a[i] > a[i+1] && a[i] > t[i]){  //h[i] == a[i]
			ans = 0;
		}else if(t[i] > t[i-1] && a[i] > a[i+1] && a[i] != t[i]){   //h[i] == t[i] == a[i]
			ans = 0;
		}
	}
    cout<<ans<<endl;
}
