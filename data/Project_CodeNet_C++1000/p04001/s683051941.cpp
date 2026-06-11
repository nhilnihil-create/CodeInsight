#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using v2 = vector<vector<int>>;

int main(){
	string s;
	cin >> s;
	ll sum = 0;
	int sz = s.size()-1;
	reverse(s.begin(), s.end());
	for(int bit = 0; bit < (1<<sz); ++bit){
		for(int i = 0; i <= sz; ++i){
			int start = i;
			int goal = 1;
			while(!(bit & (1 << i))){
				if(i == sz) break;
				i++;
				goal++;
			}
			string s2 = s.substr(start, goal);
			reverse(s2.begin(), s2.end());
			sum += stoll(s2);
		}
	}
	cout << sum << endl;
}
