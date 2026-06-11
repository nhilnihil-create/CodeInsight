#include <bits/stdc++.h>
using namespace std;
long long lcm(long long a,long long b);
//long long gcd(long long c,long long d);
int main(){
   int n,i;
   long long c=0,z=0,t[101];
   cin>>n;
   for(i=0;i<n;i++){
      cin>>t[i];
   }
   for(i=1;i<n;i++){
      t[i]=lcm(t[i],t[i-1]);
   }
      cout<<t[n-1]<<'\n';
   return 0;
}
long long lcm(long long a,long long b){
return a/__gcd(a,b)*b;
}
/*long long gcd(long long c,long long d){
    if(b==0) return a;
    return gcd(b,a%b);
}*/