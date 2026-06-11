#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

#define rep(i,n) for(int i=0; i<n; i++)

using namespace std;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

	const long long int mod = 1e9+7;
	long long int ans=1, n, x;
	stack<long long int> st;
	
	cin >> n;
	
	while(n--){
		cin >> x;
		st.push(x);
		if(x >= 2*st.size() - 1){
		}
		else{
			ans = ans * st.size() % mod;
			st.pop();
		}
	}
	
	rep(i,st.size())
		ans = ans * (i+1) % mod;
	
	cout << ans << endl;
    return 0;
}
