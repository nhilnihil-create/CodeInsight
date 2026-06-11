#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 998244353
using namespace std;
typedef pair<llint, llint> P;
typedef pair<P, llint> E;

llint n, L, T;
llint x[100005], w[100005], y[100005];
vector<llint> cvec;
vector<P> vec, vec2;
llint ans[100005];

int main(void)
{
	cin >> n >> L >> T;
	for(int i = 1; i <= n; i++) cin >> x[i] >> w[i];
	
	for(int i = 1; i <= n; i++){
		vec.push_back(P(x[i], i));
		if(w[i] == 1) y[i] = (x[i]+T)%L;
		else{
			y[i] = ((x[i]-T)%L+L)%L;
			cvec.push_back(x[i]);
		}
		vec2.push_back(P(y[i], i));
	}
	sort(vec.begin(), vec.end());
	sort(vec2.begin(), vec2.end());
	sort(cvec.begin(), cvec.end());
	llint C = (llint)cvec.size();
	
	llint p = 0;
	for(int i = 1; i <= n; i++){
		if(w[i] == 1){
			p = i;
			break;
		}
	}
	if(C == 0 || p == 0){
		for(int i = 1; i <= n; i++) cout << y[i] << endl;
		return 0;
	}
	
	llint cnt = 2*T/L*C, rem = 2*T%L, pos = x[p];
	llint idx = lower_bound(cvec.begin(), cvec.end(), x[p]) - cvec.begin();
	for(int i = idx%C; ; i = (i+1)%C){
		llint d = ((cvec[i]-pos)%L+L)%L;
		if(d == 0) d = L;
		rem -= d;
		if(rem < 0) break;
		cnt++;
		pos = cvec[i];
	}
	cnt %= n;
	
	llint a, b;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i].second == p){
			a = i;
			break;
		}
	}
	for(int i = (int)vec2.size(); i >= 0; i--){
		if(vec2[i].first == y[p]){
			b = i;
			break;
		}
	}
	
	for(int i = 0; i < n; i++){
		ans[vec[(a+cnt+i)%n].second] = vec2[(b+i)%n].first;
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << endl;
	
	return 0;
}
