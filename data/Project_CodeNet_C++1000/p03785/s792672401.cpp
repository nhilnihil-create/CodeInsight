#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,C,K;
  cin>>N>>C>>K;
  vector<int> p(N);
  for(int i=0;i<N;i++){
    cin>>p[i];
  }
  sort(p.begin(),p.end());
  int A=p[0],B=1,Z=1;
  for(int i=1;i<N;i++){
    if(B==C||p[i]-A>K){
      Z++;
      A=p[i];
      B=1;
    }
    else{
      B++;
    }
  }
  cout<<Z<<endl;
}