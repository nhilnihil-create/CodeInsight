#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
  int A,B,C;
  cin >> A >> B >> C;
  if(A==B&&B==C&&A%2==0){
    cout << -1 << endl;
    return 0;
  }
  else{
    int i = 0;
    while(A%2 == 0&& B%2 == 0&& C%2 == 0){
    int a = A;
    int b = B;
    int c = C;
      A = (b+c)/2;
      B = (a+c)/2;
      C = (a+b)/2;
      i++;
    }
    cout << i << endl;
    return 0;
  }
    
}