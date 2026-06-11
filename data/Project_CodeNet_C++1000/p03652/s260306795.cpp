#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 300003
#define MOD 1000000007
#define INF 1000000000000000000
using Graph=vector<vector<int>>;

int main(){
  int N,M;
  cin>>N>>M;
  vector<vector<int>> A(N,vector<int>(M));
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin>>A.at(i).at(j);
    }
  }

  vector<int> select(N,0);
  vector<bool> done(M,true);
  int j=1;
  int ans=N;
  while(j<M){
    vector<int> count(M,0);
    for(int i=0;i<N;i++){
      if(select.at(i)==M){
        continue;
      }
      count.at(A.at(i).at(select.at(i))-1)++;
    }
    int k=0;
    while(done.at(k)==false){
      k++;
    }
    for(int i=0;i<M;i++){
      if(done.at(i)==false){
        continue;
      }
      if(count.at(i)>count.at(k)){
        k=i;
      }
    }
    ans=min(ans,count.at(k));
    done.at(k)=false;
    for(int i=0;i<N;i++){
      if(select.at(i)==M){
        continue;
      }
      while(done.at(A.at(i).at(select.at(i))-1)==false){
        select.at(i)++;
        if(select.at(i)==M){
          break;
        }
      }
    }
    j++;
  }

  cout<<ans<<endl;
}
