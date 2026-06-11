#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 210;
char s[N];
bool check(int pos) {
	int mid = pos / 2;
	for(int i = 1; i <= mid; i++) {
		if(s[i] != s[i+mid]) return 0;
	} 
	return 1;
} 
int main() {
	
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for(int i = n-1; i >= 2; i--) {
		if(i & 1) continue;
		if(check(i)) {
			printf("%d\n", i);
			break;
		}
	}
	
	return 0;
}