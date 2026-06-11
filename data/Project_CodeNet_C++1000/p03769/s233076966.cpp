#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
stack<bool> stk;
vector<int> v1, v2;
#define pb push_back
int main(){
	ll n; cin >> n;
	n = n + 1;
	ll tmp = n;
	for(;tmp; tmp >>= 1) stk.push(tmp & 1);
	stk.pop();
	for(int x = 1; !stk.empty(); stk.pop()){
		v1.pb(x), ++x;
		if(stk.top()) v2.pb(x), ++x;
	}
	int m = v1.size() + v2.size();
	cout << m * 2 << endl;
	for(int i = 1; i <= m; ++i)
		cout << i << " ";
	for(int i = v2.size() - 1; ~i; --i)
		cout << v2[i] << " ";
	for(auto x: v1)
		cout << x << " ";
	puts("");
	return 0;
}