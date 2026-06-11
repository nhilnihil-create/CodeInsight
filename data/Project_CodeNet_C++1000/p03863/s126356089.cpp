#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
char s[1000005];int n;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	if (s[1]==s[n]){
		if (n&1) printf("Second\n");
		else printf("First\n");
	}
	else {
		if (n&1) printf("First\n");
		else printf("Second\n");
	}
	return 0;
}
