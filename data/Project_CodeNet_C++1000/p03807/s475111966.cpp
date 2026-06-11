#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A;
  cin >> A;
  int B=0,C;
  vector<int> vec(A);
  for(int i=0;i<A;i++){
    cin >> vec.at(i);
    B += vec.at(i);
  }
    if(B%2==0){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
}