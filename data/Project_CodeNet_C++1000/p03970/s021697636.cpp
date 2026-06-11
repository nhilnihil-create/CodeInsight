#include<bits/stdc++.h>
using namespace std;
char a[16],b[16]={'C','O','D','E','F','E','S','T','I','V','A','L','2','0','1','6'};
int s;
int main(){
	gets(a);
	for(int i=0;i<16;i++){
		if(a[i]!=b[i])
			s++;
	}
	cout<<s<<endl;
	return 0; 
}