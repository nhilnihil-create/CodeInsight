#include <bits/stdc++.h>
#define maxn 100100
using namespace std;

int len;

char s1[maxn],s2[maxn];

int main(){
	scanf("%s",s1);
	len=strlen(s1);
	for(int i=0;i<len;i++){
		if(s1[i]=='p') s2[i]='q';
		else if(s1[i]=='q') s2[i]='p';
		else if(s1[i]=='b') s2[i]='d';
		else if(s1[i]=='d') s2[i]='b';
	}
	for(int i=0;i<len;i++){
		if(s1[i]!=s2[len-1-i]){
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}