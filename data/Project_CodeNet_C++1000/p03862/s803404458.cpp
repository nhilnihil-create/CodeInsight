#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N,X,Z=0;
  cin>>N>>X;
  vector<int64_t> p(N);
  for(int i=0;i<N;i++){
    cin>>p.at(i);
  }
  for(int i=1;i<N;i++){
    if(p.at(i-1)>X){
      Z+=p.at(i)+p.at(i-1)-X;
      p.at(i)=0;
    }
    else if(p.at(i)+p.at(i-1)>X){
      Z+=p.at(i)+p.at(i-1)-X;
      p.at(i)=X-p.at(i-1);
    }
  }
  cout<<Z<<endl;
}