#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint a[100005];
vector<P> vec;
bool res[5];

bool get(llint x)
{
	llint p = upper_bound(vec.begin(), vec.end(), make_pair(x, 2LL)) - vec.begin() - 1;
	return vec[p].second;
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	reverse(a+1, a+n+1);
	
	if(a[1] == 1){
		if(n%2) cout << "Second" << endl;
		else cout << "First" << endl;
		return 0;
	}
	if(n == 1){
		if(a[1]%2) cout << "Second" << endl;
		else cout << "First" << endl;
		return 0;
	}
	
	llint pre = 1;
	for(int i = 1; i <= n; i++){
		if(a[i+1] != a[i]){
			llint l = (pre-1)-a[i];
			llint d = i+a[i];
			vec.push_back(make_pair(l, d%2));
			pre = i+1;
		}
	}
	
	for(int i = 1; i < vec.size(); i++){
		if(vec[i-1].second == vec[i].second) continue;
		if(vec[i].first%2 != vec[i-1].second) vec[i].first++;
	}
	
	for(int i = 0; i < 5; i++) res[i] = get(i-2);
	if(res[0]&&res[1]&&res[2] || res[2]&&res[3]&&res[4]) cout << "First" << endl;
	else cout << "Second" << endl;
	
	return 0;
}