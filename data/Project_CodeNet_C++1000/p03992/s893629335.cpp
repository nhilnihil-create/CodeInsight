#include <bits/stdc++.h>
using namespace std;

int main(){
	int i;
	string s;
	cin >> s;
	for(i = 0; i < 4; i++){
		printf("%c", s[i]);
	}
	printf(" ");
	for(i = 4; i < 12; i++){
		printf("%c", s[i]);
	}
	printf("\n");
	return 0;
}