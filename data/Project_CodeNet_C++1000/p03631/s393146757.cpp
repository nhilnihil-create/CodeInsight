#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,N1,N2,N3;
  cin >> N;
  N3=N%10;
  N/=10;
  N2=N%10;
  N/=10;
  N1=N%10;
  if(N1==N3){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}