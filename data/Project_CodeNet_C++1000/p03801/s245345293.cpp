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
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

struct BIT{
	int size;
	vector<llint> bit;
	BIT(){size = 0;}
	BIT(int s){
		size = s;
		bit.resize(size+1);
		init();
	}
	void init(){
		for(int i = 1; i <= size; i++) bit[i] = 0;
	}
	llint query(int i){
		llint ret = 0;
		while(i > 0){
			ret += bit[i];
			i -= i&(-i);
		}
		return ret;
	}
	void add(int i, llint x){
		while(i <= size){
			bit[i] += x;
			i += i&(-i);
		}
	}
};

llint n;
llint a[100005];
llint ans[100005];
vector<llint> vec;
vector<P> mvec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint mx = 0;
	mvec.push_back(P(0, 0));
	for(int i = 1; i <= n; i++){
		vec.push_back(a[i]);
		if(mx < a[i]) mvec.push_back(P(a[i], i));
		mx = max(mx, a[i]);
	}
	reverse(mvec.begin(), mvec.end());
	sort(vec.rbegin(), vec.rend());
	
	llint p = 0, cnt = 0;
	for(int i = 1; i < mvec.size(); i++){
		llint sum = (mvec[i-1].first-mvec[i].first) * cnt;
		while(p < vec.size() && mvec[i].first <= vec[p]){
			sum += vec[p]-mvec[i].first;
			cnt++;
			p++;
		}
		ans[mvec[i-1].second] += sum;
	}
	
	for(int i = 1; i <= n; i++) cout << ans[i] << endl;
	
	return 0;
}