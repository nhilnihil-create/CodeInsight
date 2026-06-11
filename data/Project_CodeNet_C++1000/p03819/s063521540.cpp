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

llint n, m;
llint l[300005], r[300005];
llint dif[300005];
llint ans[300005];
vector<llint> vec[300005];
BIT bit(300005);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
		llint len = r[i]-l[i]+1;
		vec[len].push_back(i);
		dif[len]++;
	}
	for(int i = m; i >= 1; i--) ans[i] = ans[i+1] + dif[i];
	
	for(int i = 1; i <= m; i++){
		for(int j = i; j <= m; j+=i) ans[i] += bit.query(j);
		for(int j = 0; j < vec[i].size(); j++){
			llint id = vec[i][j];
			bit.add(l[id], 1);
			bit.add(r[id]+1, -1);
		}
	}
	
	for(int i = 1; i <= m; i++) cout << ans[i] << endl;
	
	return 0;
}