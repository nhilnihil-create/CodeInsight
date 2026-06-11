#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int n = s.size();
	if(n <= 3){
		cout << "No" << endl;
		return 0;
	}

	if(s.substr(0, 4) == "YAKI"){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}
