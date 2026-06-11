#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
char s[100005];
int main(){
	int n,i,j,k,o,p,l;
	scanf("%s",s+1);
	n=strlen(s+1);
	int ok=1;
	for(i=3;i<=n;i++)
	if(s[i]!=s[i-2]){ok=0;break;}
	if(ok==1)printf("Second");
	else{
	if(s[1]==s[n]){
	if(n%2==0)printf("First");
	else printf("Second");
	}
	else{
	if(n%2==1)printf("First");
	else printf("Second");
	}
	}
	return 0;
}