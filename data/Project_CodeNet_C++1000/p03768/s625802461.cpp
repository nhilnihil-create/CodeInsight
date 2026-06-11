#include<bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 10;

int n, m, a, b, q, cor[maxn][14], qwq[maxn], qaq[maxn], c[maxn];

std::vector <int> pb[maxn];

void Work(int st, int deep, int cl)
{
    if(deep == -1) return;
    if(cor[st][deep]) return;
    cor[st][deep] = cl;
    for(int i = 0; i < pb[st].size(); ++ i) Work(pb[st][i], deep-1, cl);
}

int read()
{
	int x=0, ch= getchar(), f=1;
	while(!isdigit(ch)) if(ch == '-')f = -1, ch = getchar();
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
    for(int i=q;i>=1;i--) Work(qwq[i], qaq[i], c[i]);
    for(int i=1;i<=n;i++) std::cout<<cor[i][0]<<std::endl;
    return 0;
}