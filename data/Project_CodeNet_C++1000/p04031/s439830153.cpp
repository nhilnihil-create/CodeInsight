#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main(void){
   int N;
   cin>>N;
   vector<int> a(N);
   for(int i=0;i<N;i++){
      cin>>a[i];
   }
   int ans=1000000;
   for(int i=-100;i<=100;i++){
      int result=0;
      for(int j=0;j<N;j++){
         result+=(a[j]-i)*(a[j]-i);
      }
      ans=min(result,ans);
   }
   cout<<ans<<endl;
   return 0;
}