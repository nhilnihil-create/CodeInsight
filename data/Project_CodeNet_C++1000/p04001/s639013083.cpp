#include <bits/stdc++.h>
using namespace std;

int main(){
	string S; cin >> S;
	int64_t ret = 0, n = S.size();
	for(int i=0; i < 1<<n-1; ++i){
		bitset<10> bit(i);
		int64_t sum_i_pattern = 0;
		int st = 0;
		for(int j=0; j<n-1; ++j){
			if (bit.test(j)){
				sum_i_pattern += stol(S.substr(st, j + 1 - st));
				st = j + 1;
			}
		}
		if(st < n) sum_i_pattern += stol(S.substr(st, n - st));
		ret += sum_i_pattern;
	}
	cout << ret << endl;
}
