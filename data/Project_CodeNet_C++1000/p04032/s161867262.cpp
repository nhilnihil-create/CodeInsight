#include <bits/stdc++.h>

#include <vector>
using namespace std;


int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	
	for(int i = 0; (size_t)i < s.size() - 1 ; i++){
		if(s[i] == s[i + 1]){
			cout << i + 1 << " " << i + 2 << endl;
			return 0;
			}
	}	
	
		for(int i = 0; (size_t)i < s.size() - 2 ; i++){
			if(s[i] == s[i + 2]){
				cout << i  + 1 << " " << i + 3 << endl;
				return 0;
				}
			}
	
	
	cout << -1 << " " << -1 << endl;
	
	
	return 0;
}
