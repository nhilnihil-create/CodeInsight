#include <bits/stdc++.h>

using namespace std;

int main(){
	string ans = "";
	char x;
	int cnt = 0;
	while(cin >> x){
		if(cnt % 2 == 0) ans += x;
		cnt++;
	}
	cout << ans;
	return 0;
}