#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define ep emplace_back
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)
constexpr int mod=1000000007;
constexpr int mod1=998244353;
vector<int> dx={0,1,0,-1},dy={-1,0,1,0};
bool inside(int y,int x,int h,int w){
	if(y<h && y>=0 && x<w && x>=0) return true;
	return false;
}


vector<vector<ll>> c(51,vector<ll>(51));

void init(){
	rep(i,51) c[i][0] = 1;
	for(int i = 1; i <= 50; i++){
		for(int j = 1; j <= i; j++){
			c[i][j] += c[i - 1][j] + c[i - 1][j - 1];
		}
	}
}


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	init();
	int n,a,b;cin >> n >> a >> b;
	vector<ll> v(n);
	rep(i,n) cin >> v.at(i);
	double sum = 0;
	sort(v.rbegin(),v.rend());
	rep(i,a) sum += v.at(i);
	sum /= a;
	cout << setprecision(20) << fixed << sum << endl;
	ll ans = 0;
	int cnt = 0;
	rep(i,n) if(v.at(i) == v.at(a - 1)) cnt++;
	if(v.at(0) == v.at(a - 1)){
		for(int i = a - 1; i < b; i++){
			if(v.at(i) < v.at(0)) break;
			ans += c[cnt][i + 1];
		}
	}
	else{
		rep(i,a + 1){
			if(v.at(i) == v.at(a - 1)){
				a -= i;
				break;
			}
		}
		ans += c[cnt][a];
	}
	cout << ans << endl;
}
