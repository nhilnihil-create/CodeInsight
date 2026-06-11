#include<bits/stdc++.h>
using namespace std;int main(){long n,a,b,c,d;cin>>n>>a>>b>>c>>d;for(long k=0;k<n;k++)if(c*k-d*(n-1-k)<=b-a&&b-a<=d*k-c*(n-1-k)){cout<<"YES";return 0;}cout<<"NO"; }