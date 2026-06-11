#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
using namespace std;
char s1[100001],s2[100001];
int main(){
	cin>>s1;
	int l=strlen(s1)-1;
	for(int i=0;i<=l;i++){
		if(s1[i]=='b')
			s2[i]='d';
		if(s1[i]=='d')
			s2[i]='b';
		if(s1[i]=='p')
			s2[i]='q';
		if(s1[i]=='q')
			s2[i]='p';
	}
	for(int i=0;i<=l;i++)
		if(s1[i]!=s2[l-i]){
			cout<<"No"<<endl;
			return 0;
		}
	cout<<"Yes"<<endl; 
}