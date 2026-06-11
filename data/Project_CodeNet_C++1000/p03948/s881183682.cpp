#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define M(a,b) memset(a,b,sizeof(a))
const int MAXN = 1e5+5;
int n,t;
int num[MAXN];
int mnum[MAXN];
int main()
{
    while(~scanf("%d %d",&n,&t))
    {
        for(int i=0;i<n;i++) scanf("%d",&num[i]);

        mnum[n-1] = num[n-1];
        for(int i=n-1;i>0;i--) mnum[i-1] = max(mnum[i],num[i-1]);

        int MAX = 0;

        for(int i=0;i<n;i++) MAX = max(mnum[i]-num[i],MAX);
        int sum = 0 ;

        for(int i=0;i<n;i++) if(mnum[i]-num[i]==MAX) sum++;
        printf("%d\n",sum);
    }
    return 0;
}
