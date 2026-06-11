#include<bits/stdc++.h>
using namespace std;
const int N=5; 
int read(){
	int f=1,s=0;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='0')f=-1;
	for(;c>='0'&&c<='9';c=getchar())s=s*10+c-48;
	return f*s; 
}
const int oo=0x3f3f3f3f;
map<int,int>a;
bool work(){
	int n=read();
    for(int i=1;i<=n;i++)
    	a[read()]++;
    if(a.size()>2)return false;
	int m=a.begin()->first;
    if(a.size()==1){    	
    	if(m==n-1||m+m<=n)return true;
    	else return false;
	}
	if(a.rbegin()->first-a.begin()->first>1)return false;
	if(a.begin()->second<=m&&(m+1-a.begin()->second)*2<=n-a.begin()->second)return true;
	else return false;
}
int main(){
    if(work())printf("Yes");
    else printf("No");
    return 0;
}
