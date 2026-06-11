#include <bits/stdc++.h>
using namespace std;
int a[26];
int main(){
	string s;
	
	cin >> s;
	
	string L = "abcdefghijklmnopqrstuvwxyz";
	
	
	for(int i = 0; i < 26; i ++){
		for(int j = 0; j < s.size(); j ++){
			if(s[j] == L[i]){
				a[i] ++;
			}
		}
	}
	
	for(int i = 0; i < 26; i ++){
		if(a[i] % 2 != 0){
			cout << "No";
			return 0;
		}
	}
	
	cout << "Yes";
	return 0;
}
