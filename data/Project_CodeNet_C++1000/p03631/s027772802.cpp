#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	int n = s.size() - 1;
	for(int i = 0; i < n / 2; i++) {
		if(s[i] != s[n - i]) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
}
