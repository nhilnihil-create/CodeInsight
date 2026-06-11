#include <bits/stdc++.h>
using namespace std;

int main(){
	string S; cin >> S;
	int64_t ret = 0, n = S.size();
	for(int i=0; i < 1<<n-1; ++i){
		int st = 0;
		for(int j=0; j < n-1; ++j){
			if (i>>j & 1){
				ret += stol(S.substr(st, j + 1 - st));
				st = j + 1;
			}
		}
		ret += stol(S.substr(st, n - st));
	}
	cout << ret << endl;
}
