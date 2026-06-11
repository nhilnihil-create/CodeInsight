#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int A=S.size();
  for(int i=0;i<A;i+=2){
    cout << S.at(i);
  }
  cout << endl;
}
  