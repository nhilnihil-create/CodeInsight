#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  long long D=0;
  long long S=101;
  cin>>N;
  vector<int>vec(N);
  for(int X=0;X<N;X++){
    cin>>vec[X];
    D+=vec[X];
    if(S>vec[X]&&vec[X]%10!=0){
      S=vec[X];
    }
  }
  if(D%10!=0){
    cout<<D<<endl;
  }
  else if(S==101){
    cout<<0<<endl;
  }
  else{
    cout<<D-S<<endl;
  }
}