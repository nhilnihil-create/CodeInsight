#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
int main()
{
LL n,array1[2*N],i,T,counter=0,flag=0;
cin>>n>>T;
for(i=0;i<n;++i){
    cin>>array1[i];
}
LL works=array1[0]+T,begininig=0;
for(i=1;i<n;++i){
    if(array1[i]<=works){
        works=array1[i]+T;
    }
    else{
        counter+=works-begininig;
        works=array1[i]+T;
        begininig=array1[i];
    }
}
printf("%lld",counter+works-begininig);



    return 0;
}
