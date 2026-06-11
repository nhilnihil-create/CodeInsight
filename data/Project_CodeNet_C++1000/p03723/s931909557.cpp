#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C;
  cin >> A >> B >> C;
  for(int i=0; i<50; i++){
    if(A%2 == 1 || B%2 == 1 || C%2 == 1){
      cout << i << endl;
      return 0;
    }
    else{
      int a=(B/2)+(C/2),b=(A/2)+(C/2),c=(B/2)+(A/2);
      A=a;
      b=b;
      C=c;
    }
  }
  cout << -1 << endl;
}
