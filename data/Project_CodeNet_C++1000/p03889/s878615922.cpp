#include<bits/stdc++.h>
using namespace std;
string s,x;
int a[100010],b[100010],QwQ,QAQ;
int main(){
	cin>>s;
	x=s;
	int len=s.size();
	for(int i=0;i<len/2;i++)swap(x[i],x[len-i-1]);
	for(int i=0;i<len;i++){
		if(x[i]=='b')x[i]='d';
		else if(x[i]=='d')x[i]='b';
		else if(x[i]=='p')x[i]='q';
		else if(x[i]=='q')x[i]='p';
	}
	if(x==s)
		cout<<"Yes";
	else cout<<"No";
	return 0;
}