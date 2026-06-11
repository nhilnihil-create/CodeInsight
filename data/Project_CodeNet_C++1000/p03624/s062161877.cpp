#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string s;
	cin >> s;
	set<char> values;
	rep(i,s.size()){
		values.insert(s[i]);
	}
	for(char c = 'a' ; c < 'z' +1; c++){
		if(values.count(c)) continue;
			else{
				cout << c << endl;
				return 0;
			}
	}
	cout << "None" << endl;
}
