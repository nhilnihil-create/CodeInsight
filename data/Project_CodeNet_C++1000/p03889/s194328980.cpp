#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char a[10086000],b[10086000];
	int sum;
	cin>>a;
	sum=strlen(a);
	sum-=1;
	for(int i=0;a[i]!='\0';i++){
		if(a[i]=='b') b[sum]='d';
		if(a[i]=='d') b[sum]='b';
		if(a[i]=='p') b[sum]='q';
		if(a[i]=='q') b[sum]='p';
		sum--;
	}
	if(strcmp(a,b)==false){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	return 0;
} 