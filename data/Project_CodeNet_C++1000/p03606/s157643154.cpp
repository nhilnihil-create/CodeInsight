#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,a,b,i,x=0;
  cin >> N ;

  for(i=1;i<=N;i++){
    cin >>a >>b;
    x+=b-a+1;
    }
    
      cout <<x;
    
}
