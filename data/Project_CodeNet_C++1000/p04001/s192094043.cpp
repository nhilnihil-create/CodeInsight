#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using lond = long double;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
	string s;
	cin >> s;
	lint sum = 0;
	string pre_s = s;
	rep(bit,1 << (pre_s.size()-1)){
		lint tmp = 0;

		rep(j,pre_s.size()){
			if(bit>>j & 1){
				string s_t = s.substr(pre_s.size()-1-j);
				tmp += stol(s_t);
				s = s.substr(0,s.size()-s_t.size());
			}
		}
		tmp += stol(s);
		sum += tmp;
		s = pre_s;
	}
	cout << sum << endl;
	return 0;
}