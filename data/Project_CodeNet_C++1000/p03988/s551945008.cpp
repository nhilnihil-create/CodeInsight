#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 500009
#define MOD 1000000007
#define INF 1000000000000000000

int main(){
  int N;
  cin>>N;
  vector<int> a(N);
  map<int,int> m;
  for(int i=0;i<N;i++){
    cin>>a.at(i);
    m[a.at(i)]++;
  }
  sort(a.begin(),a.end());
  int M=a.at(N-1);
  if(M>=N){
    cout<<"Impossible"<<endl;
  }else if(M%2==0){
    bool flag=true;
    if(m[M/2]!=1){
      flag=false;
    }
    for(int i=M/2+1;i<=M;i++){
      if(m[i]<2){
        flag=false;
      }
    }
    for(int i=1;i<M/2;i++){
      if(m[i]>0){
        flag=false;
      }
    }
    if(flag){
      cout<<"Possible"<<endl;
    }else{
      cout<<"Impossible"<<endl;
    }
  }else{
    bool flag=true;
    for(int i=(M+1)/2;i<=M;i++){
      if(m[i]<2){
        flag=false;
      }
    }
    for(int i=1;i<(M+1)/2;i++){
      if(m[i]>0){
        flag=false;
      }
    }
    if(m[(M+1)/2]!=2){
      flag=false;
    }
    if(flag){
      cout<<"Possible"<<endl;
    }else{
      cout<<"Impossible"<<endl;
    }
  }
}
