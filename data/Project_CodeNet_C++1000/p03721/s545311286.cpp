#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main(void){
   long long N,K;
   cin>>N>>K;
   vector<int> a(N),b(N);
   for(int i=0;i<N;i++){
      cin>>a[i]>>b[i];
   }
   map<int,long long> result;
   for(int i=0;i<N;i++){
      result[a[i]]+=b[i];
   }
   for(auto x:result){
      K=K-x.second;
      if(K<=0){
         cout<<x.first<<endl;
         break;
      }
   }
   return 0;
}