#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

string s;

int main(void){
	cin >> s;
	vector<int> c(30);
	for(auto i : s) c.at(i-'a')++;
	for(int i = 0; i < 26; i++){
		if(c.at(i) >= 2){
			cout << "no" << endl;
			return 0;
		}
	}
	cout << "yes" << endl;

	return 0;
}
