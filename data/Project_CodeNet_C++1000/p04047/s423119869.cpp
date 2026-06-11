#include<bits/stdc++.h>
using namespace std;
  
int main(){
  int N;
  cin >> N;
  vector<int> L(2*N);
  for(int i=0;i<2*N;i++){
    cin >> L.at(i);
  }
  long long sum=0;
  sort(L.begin(),L.end());
  for(int i=0;i<2*N;i+=2){
    sum+=L.at(i);
  }
  cout << sum << endl;
}
    