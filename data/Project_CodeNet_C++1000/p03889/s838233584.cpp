//program luogu.AT2201
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int ls;
char s[100100];

int main(){
//	freopen("read.in","r",stdin);
	scanf("%s",s);
	ls=strlen(s);
	if( ls%2==1 ){
		printf("No\n");
		return 0;
	}
	for(int i=0,j=ls-1;i<j;i++,j--){
		if( ( s[i]=='p' && s[j]=='q' ) || ( s[i]=='q' && s[j]=='p' ) || ( s[i]=='d' && s[j]=='b' ) || ( s[i]=='b' && s[j]=='d' ) )
			continue;
		else{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}