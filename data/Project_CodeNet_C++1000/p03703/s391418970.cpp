#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#define llint long long 

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

llint n, k;
llint a[200005], s[200005];
P p[200005];
BIT bit(200005);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i], a[i] -= k;
	for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
	
	for(int i = 1; i <= n; i++) p[i] = P(s[i], i);
	sort(p+1, p+n+1);
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		ans += bit.query(p[i].second);
		bit.add(p[i].second, 1);
		if(p[i].first >= 0) ans++;
	}
	cout << ans << endl;
	
	return 0;
}