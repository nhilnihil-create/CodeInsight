#include <bits/stdc++.h>
using namespace std;
int main (){
  int N,M,city;
  cin>>N>>M;
  vector<int> road(N,0);
  for (int i=0;i<2*M;i++){
    cin>>city;
    for(int k=0;k<N;k++){
      if(k+1==city){
        road.at(k)+=1;
      }
    }
  }
  for (int i=0;i<N;i++){
    cout<<road.at(i)<<endl;
  }
}