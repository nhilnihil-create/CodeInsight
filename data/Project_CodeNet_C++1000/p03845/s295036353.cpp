#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
int main()
{
int n,array1[105],i,sum=0,m,temp;
scanf("%d",&n);
for(i=0;i<n;++i){
    scanf("%d",&array1[i]);
    sum+=array1[i];
}
scanf("%d",&m);
temp=sum;
while(m--){
    sum=temp;
    int p,x;
    scanf("%d %d",&p,&x);
    sum-=array1[p-1];
    sum+=x;
    printf("%d\n",sum);
}



    return 0;
}
