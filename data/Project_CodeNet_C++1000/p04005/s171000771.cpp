#include <bits/stdc++.h>
using namespace std;

int main(){
  uint64_t A,B,C,tem,ans=0;
  cin >> A >> B >> C;
  if(A % 2 == 0 || B % 2 == 0 || C % 2 == 0){
    cout << 0 << endl;
    return 0;
  }
  if(A<B){
    tem = A;
    A = B;
    B = tem;}
  if(B<C){
    tem = B;
    B = C;
    C = tem;}
  if(A<B){
    tem = A;
    A = B;
    B = tem;}
  cout << B*C << endl;
}
