#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
char s[510000];
char s2[510000];
int main(){
	int k=0;
	while(cin>>s[k]){
		//if(s[k]=='o')break;
		k++;
	}
	for(int i=0;i<k;i++){
		s2[k-i-1]=s[i];
		if(s2[k-i-1]=='b'&&s[k-i-1]!='d'){
			printf("No");
			return 0;
		}
		if(s2[k-i-1]=='d'&&s[k-i-1]!='b'){
			printf("No");
			return 0;
		}
		if(s2[k-i-1]=='q'&&s[k-i-1]!='p'){
			printf("No");
			return 0;
		}
		if(s2[k-i-1]=='p'&&s[k-i-1]!='q'){
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}