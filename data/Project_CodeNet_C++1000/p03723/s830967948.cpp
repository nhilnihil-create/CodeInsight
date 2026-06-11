#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  int count=0;
    int A,B,C;
    
  
  for(int i=1; i<=1000; i++){
    if(a%2 == 1 || b%2 == 1 || c%2 == 1){
      cout << count << endl;
      break;
    }
    
    else if(a == b && b == c){
      count = -1;
      cout << count << endl;
      break;
    }
    
    else{
      A=(b+c)/2;
      B=(c+a)/2;
      C=(a+b)/2;
      a=A;
      b=B;
      c=C;
      count++;
    }
    
  }
	return 0;
}
