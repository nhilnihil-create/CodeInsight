#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int M = 100*(N%10)+10*(N/10%10)+N/100;
  if (N==M){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}