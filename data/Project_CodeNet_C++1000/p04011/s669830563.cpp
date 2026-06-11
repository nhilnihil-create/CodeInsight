#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 200011

int main(){
   ll n,i,x,y,k,ans=0;
   cin>>n>>k>>x>>y;
   if(k>n) k=n;
   ans+=k*x;
   ans+=(n-k)*y;
   cout<<ans<<endl;
}


