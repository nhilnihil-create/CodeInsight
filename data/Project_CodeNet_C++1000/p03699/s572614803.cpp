#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  bool F=false;
  long long M=0;
  long long L=100;
  cin>>N;
  vector<int>vec(N);
  for(int X=0;X<N;X++){
    cin>>vec.at(X);
    M+=vec.at(X);
    if(vec.at(X)%10!=0 && L>vec.at(X)){
      L=vec.at(X);
      F=true;
    }
  }
  if(M%10!=0){
    cout<<M<<endl;
  }
  else if(F==false){
    cout<<0<<endl;
  }
  else{
    cout<<M-L<<endl;
  }
}