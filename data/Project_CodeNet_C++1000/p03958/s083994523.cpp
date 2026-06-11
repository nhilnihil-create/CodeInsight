#include<bits/stdc++.h>
using namespace std;

int main(){
  int K, T;
  cin >> K >> T;
  vector<int> A(T);
  for(int i=0; i<T; i++){
    cin >> A.at(i);
    A.at(i)=-A.at(i);
  }
  sort(A.begin(), A.end());
  for(int i=0; i<T; i++){
    A.at(i)=-A.at(i);
  }
  if(A.at(0)<=(K+1)/2){
    cout << 0 << endl;
  }
  else{
    if(K%2==0 && A.at(0)<K){
      cout << (A.at(0)-K/2)*2-1 << endl;
    }
    else if(K%2==1 && A.at(0)<K){
      cout << (A.at(0)-(K+1)/2)*2 << endl;
    }
    else{
      cout << K-1 << endl;
    }
  }
}