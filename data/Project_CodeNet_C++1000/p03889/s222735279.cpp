#include<iostream>
#include<cstdio>
using namespace std;
char a;
int tot=0;
char aa[1000000];
string s;
int main(){
	while(cin>>a){
		tot++;
		aa[tot]=a;
		if(a=='b')s=s+'d';
		if(a=='d')s=s+'b';
		if(a=='p')s=s+'q';
		if(a=='q')s=s+'p';
	}
	for(int i=0;i<s.size();i++){
		if(s[i]==aa[tot]){
			tot--;
		}
		else {
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}