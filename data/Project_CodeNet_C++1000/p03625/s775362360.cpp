#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N;
   cin>>N;
   vector<long long> A(N);
   for(int i=0;i<N;i++){
      cin>>A[i];
   }
   map<long long,int> result;
   for(int i=0;i<N;i++){
      result[A[i]]++;
   }
   
   vector<long long> ans;
   long long temp=0;
   for(auto x:result){
      if(x.second>=2) {
         ans.push_back(x.first);
         if(x.second>=4){
            temp=x.first;
         }
      }
   }
   sort(ans.begin(),ans.end());
   if(ans.size()<2&&temp==0){
      cout<<0<<endl;
   }else if(ans.size()<2&&temp!=0){
      cout<<temp*temp<<endl;
   }else{
      cout<<max(ans[ans.size()-1]*ans[ans.size()-2],temp*temp)<<endl;
   }
   return 0;
}