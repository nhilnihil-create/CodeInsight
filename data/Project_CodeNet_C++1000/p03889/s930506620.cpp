#include <bits/stdc++.h>
using namespace std; 

string s1, s2;

int main() {
	cin >> s1; 
	for (int i = s1.size() - 1; i >= 0; --i) 
		s2 += s1[i]; 
	for (int i = 0; i < s2.size(); ++i) {
		if (s2[i] == 'b') s2[i] = 'd'; 
		else if (s2[i] == 'd') s2[i] = 'b'; 
		else if (s2[i] == 'p') s2[i] = 'q'; 
		else if (s2[i] == 'q') s2[i] = 'p'; 
	}
	if (s1 == s2) puts("Yes");
	else puts("No"); 
	return 0; 
}