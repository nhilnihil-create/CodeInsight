#include<iostream>
#include<stack>

using namespace std;

int main(){
	string s;
	cin >> s;

	stack<char> stk;
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == 'S')
			stk.push(s[i]);
		else{
			if(stk.empty() || stk.top() == 'T')
				stk.push(s[i]);
			else
				stk.pop();
		}
	}
	cout << stk.size() << '\n';
	return 0;
}
