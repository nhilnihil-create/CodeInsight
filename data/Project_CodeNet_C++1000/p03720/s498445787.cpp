#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin>>N>>M;
  vector<int> city(N),road(2*M);
  
  for(int i;i<2*M;i++){
    cin>>road.at(i);
  }
  
  for(int i;i<2*M;i++){
    city.at(road.at(i)-1)+=1;
  }
  
  for(int i;i<N;i++){
    cout<<city.at(i)<<endl;
  } 
}