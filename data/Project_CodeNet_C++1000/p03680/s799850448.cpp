#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin>>N;
  vector<int>vec(N);
  for(int X=0;X<N;X++){
    cin>>vec.at(X);
  }
  int Y=1;
  for(int X=1;X<N;X++){
    Y=vec.at(Y-1);
    if(Y==2){
      cout<<X<<endl;
      break;
    }
  }
  if(Y!=2){
    cout<<-1<<endl;
  }
}