#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N,M;
   cin>>N>>M;
   vector<int> x(M),y(M);
   for(int i=0;i<M;i++){
      cin>>x[i]>>y[i];
      x[i]--;
      y[i]--;
   }
   vector<int> red(N,0);
   red[0]=1;
   vector<int> cnt(N,1);
   for(int i=0;i<M;i++){
      if(red[x[i]]==1){
         red[y[i]]=1;
      }
      cnt[x[i]]-=1;
      cnt[y[i]]+=1;
      if(cnt[x[i]]==0){
         red[x[i]]=0;
      }
   }
   int result=0;
   for(int i=0;i<N;i++){
      if(red[i]==1){
         result++;
      }
   }
   cout<<result<<endl;
   return 0;
}
