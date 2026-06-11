#include <bits/stdc++.h>
using namespace std;
 
int main() {
int A, B, C;
cin >> A >> B >> C;
int cnt=0;
while (A%2==0 && B%2==0 && C%2==0)
{
  cnt++;
   int a=A/2, b=B/2, c=C/2;
   A=b+c; B=a+c; C=a+b;
  if(A==B && C==B)
  {
    cnt=-1;
    break;
  }
}
cout << cnt << endl;
}