#include<bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5+10;

int cor[maxn][14], qwq[maxn], qaq[maxn], c[maxn];

std::vector <int> pb[maxn];

int n, m, a, b, q;

void paint(int v1, int d1, int c1)
{
    if(d1==-1)  return;
    if(cor[v1][d1] ) return;
    cor[v1][d1] = c1;
    for(int i =0;i<pb[v1].size();i++)
        paint(pb[v1][i], d1-1, c1);
}

int read()
{
	int x=0, ch= getchar(), f=1;
	while(!isdigit(ch)){ if(ch == '-')f = -1, ch = getchar();}
	while(isdigit(ch)) x = x *10 + ch-'0', ch = getchar();
	return x * f;
} 

int main()
{
    n=read(), m=read();
    for(int i=1;i<=m;i++) a=read(), b=read(), pb[a].push_back(b), pb[b].push_back(a);
    for(int i=1;i<=n;i++) pb[i].push_back(i);
    q=read();
    for(int i=1;i<=q;i++) qwq[i]=read(), qaq[i] = read(), c[i] = read();
    for(int i=q;i>=1;i--)  paint(qwq[i], qaq[i], c[i]);
    for(int i=1;i<=n;i++) std::cout<<cor[i][0]<<std::endl;
    return 0;
}