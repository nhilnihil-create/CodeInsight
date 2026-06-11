#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<queue>
#define re register
#define ll long long 
#define maxn 10010000
#define mod 6662333 
#define inf 2147483647
#define mem(p) memset(&p,0,sizeof(p))
using namespace std;
inline int read()
{ 
    int x=0,f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();} 
    while(isdigit(c)){x=x*10+c-48;c=getchar();}
    return x*f;
}
inline void put(ll x)
{
     if(x<0) putchar('-'),x=-x;
     if(x>9) put(x/10);
     putchar(x%10+'0');
}
char a[maxn],b[maxn];
int sum;
int main()
{
    cin>>a;
    sum=strlen(a);//求字符数组a的长度 
    sum-=1;
    for(int i=0;a[i]!='\0';i++)
	{
        if(a[i]=='b') b[sum]='d';
        if(a[i]=='d') b[sum]='b';
        if(a[i]=='p') b[sum]='q';
        if(a[i]=='q') b[sum]='p';
        sum--;
    }
    if(strcmp(a,b)==false) cout<<"Yes";
	else cout<<"No";
    return 0;
}