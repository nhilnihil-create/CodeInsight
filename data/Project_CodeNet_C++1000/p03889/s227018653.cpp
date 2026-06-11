#include <bits/stdc++.h>
using namespace std;

char s[100009],s2[100009];
int mm,len;

int main(){
	cin>>s;	len=strlen(s);	mm=len-1;
	for(int i=0;i<len;i++){
		s2[mm]=s[i];	mm--;
	}
	for(int i=0;i<len;i++){
		if(s2[i]=='b'){
			s2[i]='d';	continue;
		}
		if(s2[i]=='d'){
			s2[i]='b';	continue;
		}			
		if(s2[i]=='p'){
			s2[i]='q';	continue;
		}		
		if(s2[i]=='q'){
			s2[i]='p';	continue;
		}
	}
	for(int i=0;i<len;i++){
		if(s[i]!=s2[i]){
			printf("No");	return 0;
		}
	}
	printf("Yes");
	return 0;
}