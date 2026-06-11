#include<bits/stdc++.h>
using namespace std;

int main() {
	string a, b; cin >> a >> b;
	if(a.size() > b.size()) cout << "GREATER" << endl;
	else if(a.size() < b.size()) cout << "LESS" << endl;
	else {
		int res = 0;
		for (int i = 0; i < a.size(); i++)
		{
			if(a[i] - '0' > b[i] - '0') {
				res = 1;
				break;
			}
			else if(a[i] - '0' < b[i] - '0') {
				res = -1;
				break;
			}
		}
		if(res == 0) cout << "EQUAL" << endl;
		else if(res == 1) cout << "GREATER" << endl;
		else cout << "LESS" << endl;
	}


	return 0;
}
