
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

long long int mod(long long int a,long long int b){
    a=a%1000000007;
    b=b%1000000007;
    return (a*b)%1000000007;
}

int main() {
    long long int n,m;cin>>n>>m;
    long long int A[n],B[m];
    long long int k;cin>>k;
    for(long long int i=1;i<=n-1;i++){
        long long int b;cin>>b;
        A[i]=b-k;
        k=b;
    }
    long long int aa;cin>>aa;
    for(long long int i=1;i<=m-1;i++){
        long long int b;cin>>b;
        B[i]=b-aa;
        aa=b;
    }
    long long int a[n],b[m];
    for(int i=1;i<=n-1;i++){
        a[i]=i*(n-i);
    }
    for(int i=1;i<=m-1;i++){
        b[i]=i*(m-i);
    }
    long long int x=0,y=0;
    for(int i=1;i<=n-1;i++){
        x=x+A[i]*a[i];
    }
    for(int i=1;i<=m-1;i++){
        y=y+B[i]*b[i];
    }
    long long int ans=mod(x,y);
    printf("%lld",ans);
    
    
    return 0;
}