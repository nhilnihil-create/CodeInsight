#include <bits/stdc++.h>
using namespace std;

char str[15];

int main (){
	scanf("%s", str);
	str[4] = 0;
	puts(strcmp(str, "YAKI") ? "No" : "Yes");
	return 0;
}
