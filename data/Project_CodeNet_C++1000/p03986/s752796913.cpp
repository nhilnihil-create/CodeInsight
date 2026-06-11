#include <bits/stdc++.h>
using namespace std;

int main() {
	string x; cin >> x;
	stack<char> que;
	for (int i = 0; i < x.size(); i++)
	{
		if(que.empty()) que.push(x[i]);
		else if(que.top() == 'S' && x[i] == 'T') que.pop();
		else que.push(x[i]);
	}
	cout << que.size() << endl;

	return 0;
}

