#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	string s;
	cin >> s;
	int n;
	cin >> n;
	rep(i, s.size()){
		if(i != (int)(s.size()-1)){
			if(s[i] != 'a' && n >= 'z' - s[i] + 1){
				n -= 'z' - s[i] + 1;
				s[i] = 'a';
			}
		}else{
			int temp = s[i];
			temp -= 'a';
			temp = (temp + n) % 26;
			temp += 'a';
			s[i] = temp;
		}
	}
	cout << s << endl;
	return 0;
}