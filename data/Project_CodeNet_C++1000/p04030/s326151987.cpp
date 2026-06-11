#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define INF 1000000007


int main(){
	string s;
	cin >> s;
	int n = s.length();
	string ans = "";
	for ( int i = 0; i < n ; i++ ){
		if( s[i] == 'B' ){
			if( ans.size() == 0 )
				continue;
			else
				ans.pop_back();
		}
		else if( s[i] == '1' )
			ans += '1';
		else
			ans += '0';
	}
	cout << ans;
	return 0;
}