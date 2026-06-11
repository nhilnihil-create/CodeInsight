#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	string s;
	cin >> s;
	int n = s.size();
	int ans = 0;
	rep(i, n){
		int ai = -1;
		int mi = i%2;
		if(s.at(i) == 'g'){
			ai = 0;
		}else{
			ai = 1;
		}
		if(mi > ai){
			ans++;
		}else if(mi < ai){
			ans--;
		}
	}
	cout << ans << endl;
	return 0;
}