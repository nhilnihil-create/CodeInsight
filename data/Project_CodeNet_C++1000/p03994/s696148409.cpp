#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main(){
	string s;
	int k;
	cin >> s >> k;
	for(int i=0; i<s.size(); i++){
		if(i == s.size()-1){
			s.at(i) = (((s.at(i) - 'a') + k) % 26) + 'a';
			k = 0;
		}else if(26 - (s.at(i) - 'a') <= k && s.at(i) != 'a'){
			k -= 26 - (s.at(i) - 'a');
			s.at(i) = 'a';
		}
	}
	cout << s << endl;
	return 0;
}