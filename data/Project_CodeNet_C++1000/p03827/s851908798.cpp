#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int n;
string s;

int main(void){
	cin >> n >> s;
	int x = 0;
	int ans = 0;
	for(auto i : s){
		if(i == 'I') x++;
		else if(i == 'D') x--;
		ans = max(ans, x);
	}
	cout << ans << endl;
	return 0;
}
