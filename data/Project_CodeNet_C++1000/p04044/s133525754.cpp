#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,L;
  cin>>N>>L;
  vector<string> p(N);
  for(int i=0;i<N;i++){
    cin>>p[i];
  }
  sort(p.begin(),p.end());
  string T="";
  for(int i=0;i<N;i++){
    T+=p[i];
  }
  cout<<T<<endl;
}