#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M,c;
  cin>>N>>M;
  vector<int> city(N);
  
  for(int i;i<2*M;i++){
    cin>>c;
    city.at(c-1)++;
  }
  
  for(int i;i<N;i++){
    cout<<city.at(i)<<endl;
  } 
}