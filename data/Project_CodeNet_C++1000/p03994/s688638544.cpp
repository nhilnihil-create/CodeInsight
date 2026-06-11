#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main(){
	string s;
	int k;
	cin >> s >> k;
	rep(i, s.size()){
		if(s[i] != 'a' && 'z' - s[i] + 1 <= k){
			k -= 'z' - s[i] + 1;
			s[i] = 'a';
		}
		if(i+1 == s.size() && k > 0){
			s[i] = s[i] - 'a';
			s[i] = (s[i] + k) % 26;
			s[i] = s[i] + 'a';
		}
	}
	cout << s << endl;
	
}