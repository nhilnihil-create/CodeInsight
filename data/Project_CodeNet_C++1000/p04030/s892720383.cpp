#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

string s;

int main(void){
	cin >> s;
	stack<char> st;
	rep(i, s.size()){
		if(s[i] == '0' || s[i] == '1') st.push(s[i]);
		else if(s[i] == 'B'){
			if(st.empty()) continue;
			else st.pop();
		}
	}
	string ans = "";
	while(!st.empty()){
		ans+=st.top();
		st.pop();
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}
