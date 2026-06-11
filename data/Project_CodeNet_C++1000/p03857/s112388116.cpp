#include<bits/stdc++.h>
using namespace std;

int n,k,l;
int la[200200],lb[200200];
int gru_ans[200200];
int use_gru[200200];
bool visit[200200];

int fia(int idx)
{
    if(la[idx]==idx)return idx;
    return la[idx]=fia(la[idx]);
}

int fib(int idx)
{
    if(lb[idx]==idx)return idx;
    return lb[idx]=fib(lb[idx]);
}

void unia(int l1,int l2)
{
    la[l1]=l2;
}

void unib(int l1,int l2)
{
    lb[l1]=l2;
}

map<pair<int,int>,int> mp;

main()
{
    scanf("%d %d %d",&n,&k,&l);
    for(int i=1;i<=n;i++)
    {
        la[i]=lb[i]=i;
    }
    for(int i=0;i<k;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        if(fia(a)!=fia(b))
            unia(fia(a),fia(b));
    }
    for(int i=0;i<l;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        if(fib(a)!=fib(b))
            unib(fib(a),fib(b));
    }
    for(int i=1;i<=n;i++)
        mp[make_pair(fia(i),fib(i))]++;
    for(int i=1;i<=n;i++)
    {
        printf("%d ",mp[make_pair(fia(i),fib(i))]);
    }
}
