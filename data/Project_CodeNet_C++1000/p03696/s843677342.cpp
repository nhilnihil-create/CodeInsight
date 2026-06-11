#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	deque<char> ans;
	stack<char> st;
	cin >> n >> s;
	for(int i = 0; i < n; ++i){
		if(s[i] == '('){ 
			st.push(s[i]);
			ans.push_back(s[i]);
		}
		else{
			ans.push_back(s[i]);
			if(st.size() == 0) ans.push_front('(');
			else st.pop();
		}
	}
	while(ans.size() > 0){
		cout << ans.front();
		ans.pop_front();
	}
	while(st.size() > 0){
		cout << ')';
		st.pop();
	}
	return 0;
}