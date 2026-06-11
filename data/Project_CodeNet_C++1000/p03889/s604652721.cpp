#include<bits/stdc++.h>
using namespace std;
char a[1000001],b[1000001],c[1000001];
int l;
bool judge(){
	for (int i=0;i<l;i++)
	    if (a[i]!=b[i]) return false;
	return true;
}
int main(){
	cin>>a;
	l=strlen(a);
	for (int i=0;i<l;i++)
	    b[l-1-i]=a[i];
	for (int i=0;i<l;i++)
	    if (b[i]=='b') b[i]='d';
	        else if (b[i]=='d') b[i]='b';
	        else if (b[i]=='p') b[i]='q';
	        else if (b[i]=='q') b[i]='p';
	if (judge()) printf("Yes");
	    else printf("No");
	return 0; 
}