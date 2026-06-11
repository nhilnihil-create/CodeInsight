#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N,M;
   cin>>N>>M;
   vector<int> a(M),b(M);
   for(int i=0;i<M;i++){
      cin>>a[i]>>b[i];
      a[i]--;
      b[i]--;
   }
   vector<vector<int>> graph(N);
   for(int i=0;i<M;i++){
      graph[a[i]].push_back(b[i]);
   }
   string ans="IMPOSSIBLE";
   for(auto x:graph[0]){
      for(auto y:graph[x]){
         if(y==N-1){
            ans="POSSIBLE";
            break;
         }
      }  
   }
   cout<<ans<<endl;
   return 0;
}