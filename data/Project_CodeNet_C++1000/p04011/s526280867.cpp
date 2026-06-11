#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,k,x,y;
    scanf("%d%d%d%d",&n,&k,&x,&y);
    int ans=0;
    if (n>=k){
        ans+=k*x;
        n-=k;
    }
    else {
        ans+=n*x;
        n=0;
    }
    if (n>0){
        ans+=n*y;
    }
    printf("%d\n",ans);

}