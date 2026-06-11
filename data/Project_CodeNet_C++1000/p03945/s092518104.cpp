#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < n; ++i)

int main(){
	string s;
	cin >> s;
	
	int len = s.size();
	int ans = 0;
	string t;
	char c = s[0];
	for(int i = 1; i < len; ++i){
		if(c != s[i]){
			t += c;
			c = s[i];
		}
	}
	
	if(s[len - 1] == c){
		t += c;
	}
		
	cout << t.size() - 1 << endl;
	
	return 0;
}

