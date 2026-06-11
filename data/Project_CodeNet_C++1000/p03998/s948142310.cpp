#include <bits/stdc++.h>
using namespace std;
int main() {
  string A,B,C;
  cin >> A >> B >> C;
  vector<int>a(A.size()+1);
  for (int i = 0; i < A.size()+1; i++) {
    if (i == A.size()){
      a.at(i) = 4;
    }
    else {
      if (A.at(i) == 'a'){
        a.at(i) = 1;
      }
      else if (A.at(i) == 'b'){
        a.at(i) = 2;
      }
      else if (A.at(i) == 'c'){
        a.at(i) = 3;
      }
    }
  }
  vector<int>b(B.size()+1);
  for (int i = 0; i < B.size()+1; i++) {
    if (i == B.size()){
      b.at(i) = 5;
    }
    else {
      if (B.at(i) == 'a'){
        b.at(i) = 1;
      }
      else if (B.at(i) == 'b'){
        b.at(i) = 2;
      }
      else if (B.at(i) == 'c'){
        b.at(i) = 3;
      }
    }
  }
  vector<int>c(C.size()+1);
  for (int i = 0; i < C.size()+1; i++) {
    if (i == C.size()){
      c.at(i) = 6;
    }
    else {
      if (C.at(i) == 'a'){
        c.at(i) = 1;
      }
      else if (C.at(i) == 'b'){
        c.at(i) = 2;
      }
      else if (C.at(i) == 'c'){
        c.at(i) = 3;
      }
    }
  }
  int D = 1;
  int E = 0;
  int F = 0;
  int G = 0;
  for (int i = 0; i < A.size()+B.size()+C.size()+2; i++) {
    if (D == 1){
      D = a.at(E);
      E++;
    }
    else if (D == 2){
      D = b.at(F);
      F++;
    }
    else if (D == 3){
      D = c.at(G);
      G++;
    }
    if (D == 4){
      cout << 'A' << endl;
      return 0;
    }
    else if (D == 5){
      cout << 'B' << endl;
      return 0;
    }
    if (D == 6){
      cout << 'C' << endl;
      return 0;
    }
  }
}
      
   
  