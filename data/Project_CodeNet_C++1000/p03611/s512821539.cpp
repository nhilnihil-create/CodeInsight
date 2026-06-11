#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;cin>>N;
  vector<int>V(100000);
  for(int X=0;X<N;X++){
    int K;cin>>K;
    V[K]++;
    if(K!=99999){
      V[K+1]++;
    }
    if(K!=0){
      V[K-1]++;
    }
  }
  sort(V.begin(),V.end());
  cout<<V[99999]<<endl;
}
