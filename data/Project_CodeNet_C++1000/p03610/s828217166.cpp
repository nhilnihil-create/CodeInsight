#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string s;
	cin >> s;
	int len = s.size();
	rep(i,len){
		if(i % 2 == 1) continue;
		cout << s[i];
	}
}