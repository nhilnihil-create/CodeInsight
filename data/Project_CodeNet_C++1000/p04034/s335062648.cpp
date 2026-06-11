#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;cin >> N >> M;
  vector<int> S(N,1);
  vector<int> T(N,0);
  T[0] = 1;
  for(int j=0;j<M;j++){
    int x,y;cin >> x >> y;
    x --;
    y --;
    S[x] --;
    S[y] ++;
    if(T[x]==1){
      T[y]=1;
      if(S[x]==0){
        T[x]=0;
      }
    }
  }
  int sum=0;
  for(int i=0;i<N;i++){
    if(T[i]==1){
      sum ++;
    }
  }
  cout << sum << endl;
}