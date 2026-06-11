#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  long long M=0;
  cin>>N;
  vector<long long>vec(N);
  vector<long long>v(N);
  for(int X=0;X<N;X++){
    cin>>vec.at(X);
    cin>>v.at(X);
  }
  for(int X=N-1;X>=0;X--){
    vec.at(X)+=M;
    if(vec.at(X)%v.at(X)!=0){
      M+=v.at(X)-vec.at(X)%v.at(X);
    }
  }
  cout<<M<<endl;
}