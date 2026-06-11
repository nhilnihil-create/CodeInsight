#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> v={0,13,1,2,3,4,5,6,7,8,9,10,11,12};
  int A,B;
  cin >> A >> B;
  if(v.at(A)>v.at(B)){
    cout << "Alice" <<endl;
  }else if(v.at(A)==v.at(B)){
    cout << "Draw" << endl;
  }else{
    cout << "Bob" << endl;
  }
  return 0;
}
