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

	int n;
	string s;
	cin>>n>>s;
	int o = 0, c = 0;
	for(auto ch : s){
		if(ch == '(')o++;
		else if(o)o--;
		else c++;
	}
	string ret = "";
	while(c--)ret += '(';
	ret += s;
	while(o--)ret += ')';
	cout<<ret<<'\n';

	return 0;
}