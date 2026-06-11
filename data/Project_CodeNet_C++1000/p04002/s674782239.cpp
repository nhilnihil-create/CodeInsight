#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
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





int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h,w,n;cin >> h >> w >> n;
	map<pii,int> m;
	rep(i,n){
		int a,b;cin >> a >> b;
		for(int j = -2; j <= 0; j++){
			for(int k = -2; k <= 0; k++){
				if(a + j >= 1 && a + j <= h - 2 && b + k >= 1 && b + k <= w - 2){
					m[mp(a + j, b + k)]++;
				}
			}
		}
	}
	vector<int> ans(10);
	ll sum = 0;
	for(auto i : m){
		ans[i.second]++;
		sum++;
	}
	cout << (ll)(h - 2) * (w - 2) - sum << endl;
	rep(i,9){
		cout << ans.at(i + 1) << endl;
	}
}
