#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[100010];
int main(){
	int l;
	
	cin>>s;
	
	l=strlen(s); 
	if (s[0]==s[l-1]){
		if (l%2==0) cout<<"First";
		else cout<<"Second";
	}
	else {
		if (l%2==0) cout<<"Second";
		else cout<<"First";
	}
	
	cout<<endl;
	
	
	return 0;
}