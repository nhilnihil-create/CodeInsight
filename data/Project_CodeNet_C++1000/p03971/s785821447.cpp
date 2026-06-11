#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, a, b;
	cin >> n >> a >> b;
	int cnt = 0, abr = 1;
	string s;
	cin >> s;
	rep(i,n){
		if(s[i] == 'a'){
			if(cnt < a+b){
				cout << "Yes" << endl;
				++cnt;
			}
			else cout << "No" << endl;
		}
		else if(s[i] == 'b'){
			if(cnt < a+b && abr <= b){
				cout << "Yes" << endl;
				++cnt;
				++abr;
			}
			else cout << "No" << endl;
		}
		else cout << "No" << endl;
	}
	return 0;
}