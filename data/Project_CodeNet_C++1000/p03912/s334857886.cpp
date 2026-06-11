#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MOD 998244353
#define INF 1000000000

int main(){
  int N,M;
  cin>>N>>M;
  vector<int> X(N);
  for(int i=0;i<N;i++){
    cin>>X.at(i);
  }
  sort(X.begin(),X.end());

  vector<int> A(M,0);
  for(int i=0;i<N;i++){
    A.at(X.at(i)%M)++;
  }

  if(M%2==1){
    int ans=0;
    vector<int> count(M);
    ans+=A.at(0)/2;
    count.at(0)=A.at(0)%2;
    for(int i=1;i<=M/2;i++){
      int x=min(A.at(i),A.at(M-i));
      ans+=x;
      count.at(i)=A.at(i)-x;
      count.at(M-i)=A.at(M-i)-x;
    }

    int i=0;
    while(i<N-1){
      if(X.at(i)==X.at(i+1)){
        if(count.at(X.at(i)%M)>=2){
          count.at(X.at(i)%M)-=2;
          ans++;
          i++;
        }
      }
      i++;
    }
    cout<<ans<<endl;
  }else{
    int ans=0;
    vector<int> count(M);
    ans+=A.at(0)/2;
    count.at(0)=A.at(0)%2;
    for(int i=1;i<M/2;i++){
      int x=min(A.at(i),A.at(M-i));
      ans+=x;
      count.at(i)=A.at(i)-x;
      count.at(M-i)=A.at(M-i)-x;
    }
    ans+=A.at(M/2)/2;
    count.at(M/2)=A.at(M/2)%2;

    int i=0;
    while(i<N-1){
      if(X.at(i)==X.at(i+1)){
        if(count.at(X.at(i)%M)>=2){
          count.at(X.at(i)%M)-=2;
          ans++;
          i++;
        }
      }
      i++;
    }

    cout<<ans<<endl;
  }
}
