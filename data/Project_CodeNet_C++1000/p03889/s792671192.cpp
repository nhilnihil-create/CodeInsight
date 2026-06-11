#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s1[100100],s2[100100];

int main(){
	int cnt=0;
	cin>>s1;
	int len=strlen(s1);
	for(int i=len-1;i>=0;i--){
		s2[cnt]=s1[i];
		if(s2[cnt]=='q')
			s2[cnt]='p';
		else if(s2[cnt]=='p')
			s2[cnt]='q';
		else if(s2[cnt]=='b')
			s2[cnt]='d';
		else if(s2[cnt]=='d')
			s2[cnt]='b';
		cnt++;
	}
	for(int i=0;i<len;i++){
		if(s1[i]!=s2[i]){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
} 