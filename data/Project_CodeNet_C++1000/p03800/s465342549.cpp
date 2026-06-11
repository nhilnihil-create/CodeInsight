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





int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;cin >> n;
	string s;cin >> s;
	rep(i,2){
		rep(j,2){
			vector<int> a(n + 2);
			a[1] = i;
			a[2] = j;
			for(int k = 2; k < n; k++){
				if(a[k]){
					if(s[k - 1] == 'o'){
						a[k + 1] = a[k- 1];
					}
					else{
						a[k + 1] = a[k- 1] ^ 1;
					}
				}
				else{
					if(s[k - 1] == 'o'){
						a[k + 1] = a[k- 1] ^ 1;
					}
					else{
						a[k + 1] = a[k- 1];
					}
				}
			}
			bool ok = true;
			if(a[1]){
				if(s[0] == 'o'){
					if(a[n] != a[2]) ok = false;
				}
				else{
					if(a[n] == a[2]) ok = false;
				}
			}
			else{
				if(s[0] == 'o'){
					if(a[n] == a[2]) ok = false;
				}
				else{
					if(a[n] != a[2]) ok = false;
				}
			}
			if(a[n]){
				if(s[n - 1] == 'o'){
					if(a[1] != a[n - 1]) ok = false;
				}
				else{
					if(a[1] == a[n - 1]) ok = false;
				}
			}
			else{
				if(s[n - 1] == 'o'){
					if(a[1] == a[n - 1]) ok = false;
				}
				else{
					if(a[1] != a[n - 1]) ok = false;
				}
			}
			if(ok){
				for(int k = 1; k <= n; k++){
					if(a[k]) cout << "S";
					else cout << "W";
				}
				cout << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
}
