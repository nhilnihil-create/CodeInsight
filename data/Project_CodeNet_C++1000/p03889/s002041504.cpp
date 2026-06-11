#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char ss[100010];
int len;

char mir(int x){
	if(ss[x]=='b') return 'd';
	if(ss[x]=='d') return 'b';
	if(ss[x]=='p') return 'q';
	if(ss[x]=='q') return 'p';
} 

int main(){
	cin>>ss; len=strlen(ss);
	for(int i=0;i<len;i++)
		if(mir(len-i-1)!=ss[i]){
			cout<<"No"<<endl;
			return 0;
		}
	cout<<"Yes"<<endl;
	return 0;
}