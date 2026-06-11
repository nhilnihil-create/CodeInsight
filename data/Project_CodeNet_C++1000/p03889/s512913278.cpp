#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[100010];
char s1[100010];
int len;
int main(){
	cin >> s;
	len = strlen(s);
	for(int i = len - 1, j = 0; i >= 0; i--, j++){
		if(s[i] == 'd') s1[j] = 'b';
		else if(s[i] == 'b') s1[j] = 'd';
		else if(s[i] == 'p') s1[j] = 'q';
		else if(s[i] == 'q') s1[j] = 'p';
	}
	for(int i = 0; i <= len; i++)
		if(s[i] != s1[i]){
			printf("No");
			return 0;
		}
	printf("Yes");
	return 0;
}