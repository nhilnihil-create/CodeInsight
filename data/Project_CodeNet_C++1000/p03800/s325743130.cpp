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
	int n;cin >> n;
	string s;cin >> s;
	vector<bool> a(n);
	vector<pair<bool,bool>> b = {{true, true}, {true, false}, {false, true}, {false, false}};
	bool ok = false;
	rep(i,4){
		bool ok1 = true;
		a.at(0) = b.at(i).first;
		a.at(1) = b.at(i).second;
		for(int j = 1; j < n - 1; j++){
			if(s.at(j) == 'o'){
				if(a.at(j)) a.at(j + 1) = a.at(j - 1);
				else a.at(j + 1) = (a.at(j - 1) ^ 1);
			}
			else{
				if(!a.at(j)) a.at(j + 1) = a.at(j - 1);
				else a.at(j + 1) = (a.at(j - 1) ^ 1);
			}
		}
		rep(j,n){
			if(s.at(j) == 'o'){
				if(a.at(j)){
					if(a.at((j - 1 + n) % n) != a.at((j + 1) % n)) ok1 = false;
				}
				else{
					if(a.at((j - 1 + n) % n) == a.at((j + 1) % n)) ok1 = false;
				}
			}
			else{
				if(a.at(j)){
					if(a.at((j - 1 + n) % n) == a.at((j + 1) % n)) ok1 = false;
				}
				else{
					if(a.at((j - 1 + n) % n) != a.at((j + 1) % n)) ok1 = false;
				}
			}
		}
		if(ok1){
			ok = true;
			break;
		}
	}
	if(ok){
		rep(i,n){
			if(a.at(i)) cout << 'S';
			else cout << 'W';
		}
		cout << endl;
	}
	else cout << -1 << endl;
}