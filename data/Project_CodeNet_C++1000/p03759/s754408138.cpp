#include <bits/stdc++.h>
using namespace std;

#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

signed main(){
	int a, b, c;
	cin >> a >> b >> c;
	if(b-a == c-b){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}

	return 0;
}
