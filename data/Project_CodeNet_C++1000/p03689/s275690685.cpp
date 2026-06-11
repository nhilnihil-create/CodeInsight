#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 505
using namespace std;
typedef long long ll;
int H,W,h,w;
ll a[maxn][maxn];
int main()
{
    cin>>H>>W>>h>>w;
    for(int i=1;i<=H;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(i%h==0&&j%w==0)  a[i][j]=-4000*h*w+3999;
        }
    }
    long long sum=0;
    for(int i=1;i<=H;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(a[i][j]==0)  sum+=4000,a[i][j]=4000;
            else sum+=(ll)a[i][j];
        }
    }
    if(sum<=0)  puts("No");
    else{
        puts("Yes");
        for(int i=1;i<=H;i++)
        {
            for(int j=1;j<=W;j++)  printf("%d ",a[i][j]);
            puts("");
        }
    }
    return 0;
}