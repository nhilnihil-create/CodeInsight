#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char a[110];
int main(){
	scanf("%s", a + 1);
	printf("%c%d%c\n", a[1], strlen(a + 1) - 2, a[strlen(a + 1)]);
	return 0;
} 