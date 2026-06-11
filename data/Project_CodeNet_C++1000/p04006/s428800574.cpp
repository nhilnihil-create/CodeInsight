#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<stack>
#define pii std::pair<int,int>
using namespace std;

long long a[2010]={0};
long long b[2010][2010]={0};

int main()
{   
	long long n,x,i,j,sum,minx,temp;
    scanf("%lld%lld",&n,&x);
    for(i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(i=1;i<=n;i++){
        b[i][0]=a[i];
        for(j=1;j<n;j++){
            temp=i-j;
            if(temp<=0)
                temp=n+temp;
            b[i][j]=min(b[i][j-1],a[temp]);  
        }
    }
    minx=99999999999999;
    for(i=0;i<n;i++){
        sum=0;
        for(j=1;j<=n;j++)
            sum+=b[j][i];
        sum+=i*x;
        minx=min(sum,minx);
    }
    printf("%lld\n",minx);
}