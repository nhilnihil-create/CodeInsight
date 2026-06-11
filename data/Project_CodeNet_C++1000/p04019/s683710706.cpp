#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=114514;
char st[N];
int p[114514];
int main()
{
    scanf("%s",st+1);
    int n=strlen(st+1);
    for(int i=1;i<=n;i++)p[st[i]]=1;
    if(p['E']!=p['W']||p['N']!=p['S'])puts("No");
    else puts("Yes");
}