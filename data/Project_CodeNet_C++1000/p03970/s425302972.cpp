#include<bits/stdc++.h>
using namespace std;
string s;
int num=0;
string a="CODEFESTIVAL2016";
int main(){
	cin>>s;
	for(int i=1;i<=16;i++)
		if(a[i-1]!=s[i-1])num++;
	cout<<num<<endl;
	
}