#include<bits/stdc++.h>
using namespace std;
string s,p;
int m,n,j,k,l,sum,ans,r;
string fz(string h)
{
	char t,y;
	int len=h.size();
	for(int i=0; i<len/2; i++)
	{
		t=h[i];
		y=h[len-i-1];
		h[i]=y;
		h[len-i-1]=t;
	}
	return h;
}
int main()
{
	getline(cin,s);
	p=fz(s);
	l=p.size();
	for(int i=0; i<l; i++)
	{
		if(p[i]=='b')p[i]='d';
		else if(p[i]=='d')p[i]='b';
		else if(p[i]=='p')p[i]='q';
		else if(p[i]=='q')p[i]='p';
	}
	if(p==s)printf("Yes\n");
	else printf("No\n");
	return 0;
}