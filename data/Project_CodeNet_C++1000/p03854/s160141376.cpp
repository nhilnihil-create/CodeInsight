#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

string s;

int main(void){
	cin >> s;
	while(1){
		lli n = s.size();
		if(n == 0) break;
		lli e = -1;
		if(n >= 7 && s.substr(n-7) == "dreamer") e = 7;
		if(n >= 6 && s.substr(n-6) == "eraser") e = 6;
		if(n >= 5 && (s.substr(n-5) == "dream" || s.substr(n-5) == "erase")) e = 5;

		if(e == -1){
			cout << "NO" << endl;
			return 0;
		}else{
			s.erase(n-e);
		}
	}
	cout << "YES" << endl;
	return 0;
}
