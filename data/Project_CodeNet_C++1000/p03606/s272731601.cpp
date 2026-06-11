#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;

 vector<int> l(N);
  vector<int> r(N);
  int sum=0;
  
  for(int i=0;i<N;i++){
  cin >> l.at(i) >> r.at(i) ;
    sum+=(r.at(i)-l.at(i)+1);
  }
  
  cout << sum ;
  
}