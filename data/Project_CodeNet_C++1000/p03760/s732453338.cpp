#include <bits/stdc++.h>
using namespace std;

int main() {
  string O,E,P,S;
  cin>>O>>E;
  S=O+E;
  int N=S.size();
  
  for(int i=0;i<N;i++){
      if (i % 2 == 0){
        P = P + O.at(i/2);
      } else{
        P = P + E.at(i/2);
      }
  }
  cout<<P<<endl;
  
}
