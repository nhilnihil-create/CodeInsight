#include<iostream>
#include<vector>

using namespace std;
#define int long long

signed main(){

   int N;
   cin>> N;

   int m=0;
   for(int i=1; i<=N; i++){
      int s=i*(i+1)/2;
      if(s>=N){
         m=i;
         break;
      }
   }
   int s=m*(m+1)/2;
   vector<int> ans;
   for(int i=m; i>=1; i--){
      int S=i*(i-1)/2;
      if(N>S){
         ans.push_back(i);
         N-=i;
      }
      if(N==0) break;
   }

   for(int a: ans){
      cout<< a<< endl;
   }
   return 0;
}
