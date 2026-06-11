#include <bits/stdc++.h>
using namespace std;

int main () {
  int N;
  string S;
  cin >> N >> S;
  int count1 = 0;
  int count2 = 0;
  vector<int>A(N,0);
  vector<int>B(N,0);
  int a = 0;
  int b = 0;
  int c = 0;
            
  for (int i = 0; i < N; i++) {
    if (S.at(i) == '('){
      count1++;
      a++;
    }
    else {
      count2++;
      b++;
    }
    A.at(i) = a;
    B.at(i) = b;
    if (B.at(i) - A.at(i) > c){
      c = B.at(i) - A.at(i);
    }
  }
  
  for (int i = 0; i < c; i++) {
    cout << '(';
  }  
  cout << S;
  for (int i = 0; i < a+c-b; i++) {
    cout << ')';
  } 
  cout << endl;
}
  