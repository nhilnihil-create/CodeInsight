#include <bits/stdc++.h>
using namespace std;

int main(){
  long long A, B, C;
  cin >> A >> B >> C;
  long long count = 0;
  for(;A % 2 == 0 && B % 2 == 0 && C % 2 == 0;){
    if(A == B && B == C){
      count = -1;
      break;
    }
    long long a, b, c;
    a = A / 2;
    b = B / 2;
    c = C / 2;
    A = b + c;
    B = a + c;
    C = a + b;
    count++;
  }
  cout << count << endl;
}
