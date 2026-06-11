#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N ;
  vector<int> A(N);
  int l,c=0;
  
  for (int i=0;i<N;i++){
    cin >> A.at(i);
  }  
  l=A.at(0);

  for (int j=0;j<N;j++){
    c++;
    if (l==2){
      cout << c;break;}
    else {
      l=A.at(l-1);}
  }
  
  if (c==N){
    cout << -1 << endl;}

}