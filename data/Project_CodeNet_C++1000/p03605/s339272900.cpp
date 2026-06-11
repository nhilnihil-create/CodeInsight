#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  bool a=false;
  if(N%10==9){
    a=true;
  }
  N/=10;
  if(N%10==9){
    a=true;
  }
  if(a){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}