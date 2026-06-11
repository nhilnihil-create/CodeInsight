#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
string a;
int i,o;
bool t;
int main(){
	cin>>a;
	t=false;
	o=a.size();
	for(i=0;i<=o-1;i++){
		if(a[i]=='b'&&a[o-i-1]=='d')continue;
		if(a[i]=='q'&&a[o-i-1]=='p')continue;
		if(a[i]=='d'&&a[o-i-1]=='b')continue;
		if(a[i]=='p'&&a[o-i-1]=='q')continue;
		t=true;break;
	}
	if(t)cout<<"No";
	else cout<<"Yes";
	return 0;
}
