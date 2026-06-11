#include<bits/stdc++.h>
using namespace std;
int main(){
	char a[2000],b[16]={'C','O','D','E','F','E','S','T','I','V','A','L','2','0','1','6'};
	int len,i,s=0;
	cin>>a;
	len=strlen(a);
	for(i=0;i<len;i++){
		if(a[i]!=b[i])s++;
	}
	cout<<s;
}