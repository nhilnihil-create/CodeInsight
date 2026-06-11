#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i = 0; i<n; ++i)
#define REP(i,n) for(int i = 1; i<=n; ++i)
#define all(x) begin(x),end(x)
#define show(obj) {for(auto x:obj)cout<<x<<' ';cout<<endl;}
#define line "----------"
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> LP;
const int inf = 1001001000;
const ll INF = 1LL<<60;
const int MOD = (int)1e9 + 7;

char next_anima(char who, char ans, char form){
	bool res = ((form == 'S')? true : false);
	if(who == 'S'){
		if(ans == 'x')res = !res;
	}else{
		if(ans == 'o')res = !res;
	}
	return ((res)? 'S' : 'W');
}

int main(){
	int N;
	string s;
	cin >> N >> s;
	rep(i,2){
		rep(j,2){
			vector<char> ans(N);
			if(i == 0)ans[0] = 'S';
			else ans[0] = 'W';
			if(j == 0)ans[1] = 'S';
			else ans[1] = 'W';
			for(int k = 1; k < N-1; ++k){
				ans[k+1] = next_anima(ans[k], s[k], ans[k-1]);
			}
			if(ans[0] == next_anima(ans[N-1], s[N-1], ans[N-2]) && ans[1] == next_anima(ans[0], s[0], ans[N-1])){
				for(auto x:ans)cout << x;
				cout << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}
