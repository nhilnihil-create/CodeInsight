#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> V(N);
  vector<int> Z(N);
  for(int i=0;i<N;i++){
    cin>>V.at(i);
    cin>>Z.at(i);
 
  }
  sort(V.begin(),V.end());
  reverse(V.begin(),V.end());
  sort(Z.begin(),Z.end());
  cout<<V.at(0)+Z.at(0)<<endl;
  
 
}


