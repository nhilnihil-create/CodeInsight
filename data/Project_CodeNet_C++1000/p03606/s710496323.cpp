#include<bits/stdc++.h>
#include<cstdlib>
#include<cmath>
using namespace std;
int main(){
  int N; cin>>N;
  int P=0;
  vector<vector<int>> S(N,vector<int>(2));
  for(int i=0; i<N; i++){
    for(int j=0;j<2; j++){
      cin>>S.at(i).at(j);
    }
    P+=(S.at(i).at(1)-S.at(i).at(0)+1);
  }
  cout<<P<<endl;
}
      
