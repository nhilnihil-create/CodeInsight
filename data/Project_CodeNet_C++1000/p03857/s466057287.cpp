#include<bits/stdc++.h>
using namespace std;
const int N=200010;
inline int read(){
	int f=1,w=0;char x=0;
	while(!(x>='0'&&x<='9'))
	{
		x=getchar();
		if(x=='-') f=-1;
	}
	while(x!=EOF&&x>='0'&&x<='9')
	{
		w=(w<<3)+(w<<1)+(x^48);
		x=getchar();
	}
	return f*w;
}
int n,k,l,r[N],t[N];
map < pair < int,int >,int > mp;
int find(int x,int *f){
	if(f[x]==x) return x;
	else return f[x]=find(f[x],f);
}
void join(int x,int y,int *f){
	int px=find(x,f),py=find(y,f);
    if(px!=py) f[px]=py;
}
int main(){
	n=read(),k=read(),l=read();
	for(int i=1;i<=n;i++)
        r[i]=i,t[i]=i;
	for(int i=1;i<=k;i++)
	{
		int x=read(),y=read();
		join(x,y,r);
	}
	for(int i=1;i<=l;i++)
	{
		int x=read(),y=read();
		join(x,y,t);
	}
	for(int i = 1;i<=n;i++)
    {
        find(i,r);
        find(i,t);
    }
    for(int i = 1;i<=n;i++)
	    mp[make_pair(r[i],t[i])]++;
	for(int i = 1;i<=n;i++)
		cout<<mp[make_pair(r[i],t[i])]<<" ";
	return 0;
}