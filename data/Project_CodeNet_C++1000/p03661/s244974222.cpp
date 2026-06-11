#include<cstdio>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<limits>
#include<bitset>

using namespace std;

/*
for(int i=0;i<n;i++)
printf("%d\n",n)
scanf("%d",&n)
*/

int n,a[300000];
long long int b,sm=0,sa,r=0;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sm+=a[i];
    }
    for(int i=0;i<n-1;i++){
        b+=a[i];
        sa=sm-b;
        //printf("%d %d\n",b,sa);
        if(i) r=min(abs(sa-b),r);
        else r=abs(sa-b);
        
    }
    printf("%lld\n",r);
}
