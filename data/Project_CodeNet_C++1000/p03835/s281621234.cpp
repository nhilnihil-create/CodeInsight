#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
int main()
{
int i,j,k,sum,counter=0;
scanf("%d %d",&k,&sum);
for(i=0;i<=k;++i){
    for(j=0;j<=k;++j){
        if((sum-(i+j))<=k&&(sum-(i+j))>=0){
            counter++;
        }
    }
}
printf("%d",counter);

    return 0;
}
