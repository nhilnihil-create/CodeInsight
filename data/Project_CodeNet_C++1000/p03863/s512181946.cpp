#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

char s[N];

int main(){
	scanf("%s" , s + 1);
	int n = strlen(s + 1);
	puts((s[1] == s[n]) ^ (n & 1) ? "First" : "Second");
	return 0;
} 