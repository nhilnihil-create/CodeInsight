#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+10;
int ln[maxn],tot,kl,v1,v2,m,x,y,n;
struct asuka{int pos,val;}q[maxn];
void add(int pos,int val){q[++tot].pos=pos,q[tot].val=val;}
bool cmp(asuka a,asuka b){return a.pos<b.pos;}
vector<int>s,t;
signed main() 
{
    cin>>n;
    n++;
    int p=101;
    while(n>1) 
    {
        if(n&1)t.push_back(--p),n--;
        else s.push_back(--p),n>>=1;
    }
    int m=s.size()+t.size();
    printf("%lld\n",m<<1);
    for(int i=0;i<(int)t.size();i++)
        printf("%lld ",t[i]);
    for(int i=s.size()-1;~i;i--)
        printf("%lld ",s[i]);
    for(int i=100-m+1;i<=100;i++)
        printf("%lld ",i);
    return 0;
}
/*
做一次二进制分解，然后一组一组摆过去。
对于第i位，重复搞个1到i摆在一起，再单独开两个值摆一起。
这可能一下就炸了
……
答案非常优雅
在右边搞个排列，那么左边上升子序列的数量就是答案。
从小到大放，如果放左边，答案+1，放右边，答案翻倍再+1。
啊 丑陋 丑陋的性质
假装空串也合法就不会这么丑陋了
放左边，答案+1，右边，答案翻倍
直接构造就行



*/