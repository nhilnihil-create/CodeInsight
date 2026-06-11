#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;

int main() {
 string A, B;
 cin >> A;
 cin >> B;

 if(A.size() > B.size()) { cout << "GREATER"; return 0; }
 else if(A.size() < B.size()) { cout << "LESS"; return 0; }
 else {
   for(int i = 0; i < A.size(); i++) {
     if(A[i] > B[i]) { cout << "GREATER"; return 0; }
     else if(A[i] < B[i]) { cout << "LESS"; return 0; }
   }
 }

 cout << "EQUAL";
 
  return 0;
}