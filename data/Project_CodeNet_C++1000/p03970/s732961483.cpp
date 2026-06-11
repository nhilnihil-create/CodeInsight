// "include" {{{
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <cstring>
// }}}
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define int long long
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	string k = "CODEFESTIVAL2016";
	int n = s.size();
	int cnt = 0;
	rep(i,n){
		if(s[i] != k[i]) ++cnt;
	}
	cout << cnt << '\n';
	return 0;
}
