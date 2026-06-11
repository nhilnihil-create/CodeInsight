#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long x,y,n,k;
    cin>>n>>k>>x>>y;
    if(n>=k)
     cout<<x*k+(n-k)*y;
    else if(k>n)
     cout<<x*n;
    return 0;
  }
     
   