#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}

int n,m;
int a[100001];
vector<int> e[100001];
int vis[100001];
int f[100001][15];
struct node{
	int v,d,c;
}q[100001];
void func(int u,int d,int c)
{
	if(vis[u]>=d)return;
	vis[u]=d;
	if(!a[u])a[u]=c;
	if(d==0) return;
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		func(v,d-1,c);
	}
}
int main()
{
	cin>>n>>m;
	int u,v;
	for(int i=1;i<=n;i++)
		e[i].clear();
	memset(a,0,sizeof(a));
	memset(vis,-1,sizeof(vis));
	for(int i=0;i<m;i++)
	{
		read(u); 
		read(v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int s;
	cin>>s;
	for(int i=0;i<s;i++){
		read(q[i].v);
		read(q[i].d);
		read(q[i].c);
	}
	for(int i=s-1;i>=0;i--)
	{
		func(q[i].v,q[i].d,q[i].c);
	}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<endl;
	
	return 0;

}
