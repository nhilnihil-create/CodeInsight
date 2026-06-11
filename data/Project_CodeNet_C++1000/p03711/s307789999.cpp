#include <bits/stdc++.h>
using namespace std;

int main() {
  set<int> S;

  S.insert(1);
  S.insert(3);
  S.insert(5);
  S.insert(7);
  S.insert(8);
  S.insert(10);
  S.insert(12);
  
  set<int> B;

  B.insert(4);
  B.insert(6);
  B.insert(9);
  B.insert(11);
  
    set<int> C;

  C.insert(2);
  
  int a, b ;
  cin >> a >> b ;
  
  cout << ( (S.count(a)&&S.count(b))||
           (B.count(a)&&B.count(b))||
           (C.count(a)&&C.count(b)) ?
           "Yes" : "No"
           )
    << endl;
}