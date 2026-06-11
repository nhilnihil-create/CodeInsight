#include<bits/stdc++.h>          
using namespace std;
 
#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define int long long
#define mk_p(a,b)	make_pair((a),(b))
#define fixed(n) fixed<<setprecision((n))
using pii = pair<int,int>;
constexpr int INF  = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr long long MOD = 1000000007;

int gcd(int a,int b){return b ? gcd(b,a%b) : a;}
int lcm(int a,int b){return a/gcd(a,b)*b;}

vector<int> p;
vector<int> s;
vector<bool> in;

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	in.resize(n+1);
	reps(i,n){
		int a;
		cin >> a;
		if(a == i) in[i] = true;
	}
	int cnt = 0;
	int cntb = 0;
	bool flg = false;
	reps(i,n){
		if(in[i]){
			cntb++;
		}
		else{
			cnt += (cntb + 2 -1) / 2;
			cntb = 0;
		}
	}
	cnt += (cntb + 2 -1) / 2;
	cout << cnt << '\n';

	return 0;
}
