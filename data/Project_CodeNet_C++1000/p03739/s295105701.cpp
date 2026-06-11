#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
LL n,array1[2*N];
LL solve(LL num){
    LL sum=num,counter=0;
for(LL i=1;i<n;++i){
     LL temp_sum=sum+array1[i];
     if(sum>0){
        if(temp_sum>=0){
            counter+=temp_sum+1;
            temp_sum=-1;
        }
     }
     else if(sum<0){
        if(temp_sum<=0){
            counter+=abs(temp_sum)+1;
            temp_sum=1;
        }
     }
     sum=temp_sum;
}
   return counter;
}
int main()
{
LL i,sum=0;
scanf("%lld",&n);
for(i=0;i<n;++i){
    scanf("%lld",&array1[i]);
}
LL mini;
if(array1[0]==0){
        mini=min(solve(1),solve(-1))+1;
}
else{
    LL choice1=solve(array1[0]);
    LL choice2=(array1[0]>0)?solve(-1)+array1[0]+1:solve(1)+abs(array1[0])+1;
    mini=min(choice1,choice2);
}
printf("%lld",mini);



    return 0;
}
