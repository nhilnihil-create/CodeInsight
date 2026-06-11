#include<bits/stdc++.h>
using namespace std;
#define int long long int 

const int mod=1e9+7;
int fact[100005];
void cal()
{
    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<=100000;i++)
    fact[i]=(fact[i-1]*i)%mod;
}

int32_t main()
{
    cal();
     int n,m;
      cin>>n>>m;
      if(abs(m-n)>1)
      cout<<0<<endl;
    else  if(n!=m)
      cout<<((fact[n]*fact[m])%mod)<<endl;
     else 
     cout<<((2*(fact[n]*fact[m])%mod)%mod)<<endl;
}
