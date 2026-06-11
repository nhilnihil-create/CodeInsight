#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	string s;
	cin>>s;
	int cnt = 0;
	for(int i = 1; i < s.size(); i++){
		if(s[i] != s[i - 1])cnt++;
	}
	cout<<cnt<<endl;

	return 0;
}