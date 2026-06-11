#include<bits/stdc++.h>
using namespace std;

int main() {
  int W,A,B;
  cin >> W >> A >> B;
  if(A+W<=B){
    cout << max(B-A-W,0) << endl;
  }
  else{
    cout << max(A-B-W,0) << endl;
  }
}