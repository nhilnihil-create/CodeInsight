#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int A, B, C, a, b, c, cnt=0;
  cin >> A >> B >> C;
  if(A==B && A==C && A%2==0) cnt=-1;
  else{
    while(1){
      if(A%2!=0 || B%2!=0 || C%2!=0) break;
      a=A; b=B; c=C;
      A=b/2+c/2;
      B=a/2+c/2;
      C=a/2+b/2;
      cnt++;
    }
  }
  cout << cnt << endl;
}