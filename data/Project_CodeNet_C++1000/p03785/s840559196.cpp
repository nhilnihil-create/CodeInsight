#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N,C,K;
   cin>>N>>C>>K;
   vector<int> T(N);
   for(int i=0;i<N;i++){
      cin>>T[i];
   }
   sort(T.begin(),T.end());
   int ans=0;
   for(int i=0;i<N;){
      ans++;
      int first=i;
      while(i<N&&T[first]<=T[i]&&T[i]<=T[first]+K&&(i-first+1)<=C){
         i++;
      }
   }
   cout<<ans<<endl;
   return 0;
}
