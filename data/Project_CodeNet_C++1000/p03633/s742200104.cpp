#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
   if(b==0) return a;
   else return gcd(b,a%b);
}
int main(void){
   int N;
   cin>>N;
   vector<long long> T(N);
   for(int i=0;i<N;i++){
      cin>>T[i];
   }
   long long ans=1;
   for(int i=0;i<N;i++){
      ans=ans/gcd(ans,T[i]);
      ans*=T[i];
   }
   cout<<ans<<endl;
   return 0;
}