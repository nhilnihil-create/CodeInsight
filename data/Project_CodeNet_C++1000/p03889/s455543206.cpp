#include<bits/stdc++.h>
using namespace std;
inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
bool t=1;
string s;
char ss[1000001];
int main()
{
	cin>>s;
	int l=s.size();
	for(int i=0;i<s.size();++i)
	 {
	 	if(s[l-i-1]=='p')
	 	 ss[i]='q';
	 	if(s[l-i-1]=='q')
	 	 ss[i]='p';
	 	if(s[l-i-1]=='d')
	 	 ss[i]='b';
	 	if(s[l-i-1]=='b')
	 	 ss[i]='d';
	 }
	for(int i=0;i<l;++i)
	 {
	 	if(s[i]!=ss[i])
	 	 t=0;
	 }
	if(t==1)
	 cout<<"Yes\n";
	else
	 cout<<"No\n";
	return 0;
}