#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+500;
int w[N],n;
int cmp(const int &a,const int &b){return a>b;}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",w+i);
    sort(w,w+n,cmp);
    int i=0;
    for(;i<n;i++)if(w[i+1]<=i+1)break;
    int j=i+1;
    for(;j<n;j++)if(w[j]<=i)break;
    if(((w[i]-i)&1)&&((j-i)&1)){puts("Second");}
    else puts("First");
}