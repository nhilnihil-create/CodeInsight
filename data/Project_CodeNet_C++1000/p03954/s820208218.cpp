#include <iostream>
int a[200005],n,b[200005],i,l,A,M,r=200005;
int P(int x){for(i=1;i<n*2;i++)b[i]=(a[i]>=x);b[0]=b[1];
for(i=n;i<=n+n;i++){if(b[i]==b[i+1])return b[i];if(b[n+n-i]==b[n+n-i-1])return b[n+n-i];}}
int main(){std::cin>>n;for(i=1;i<n*2;i++)std::cin>>a[i];
while(l<=r){M=(l+r)/2;if(P(M))l=M+1,A=M;else r=M-1;}std::cout<<A;}