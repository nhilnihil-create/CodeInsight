#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

string s;

int main(void){
	cin >> s;
	vector<int> c(26);
	rep(i, s.size()) c[s[i]-'a']++;
	rep(i, 26){
		if(c[i]%2 == 1){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
