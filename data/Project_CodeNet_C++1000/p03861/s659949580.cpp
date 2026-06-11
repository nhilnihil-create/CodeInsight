#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int A, B, X;
  cin >> A >> B >> X;
  
  long long int gap = X - (A % X);
  if (gap != X){
    A += gap;
  }
  
  long long int ans;
  if (B - A >= 0){
    ans = ((B - A) / X) + 1;
  }
  else{
    ans = 0;
  }
  
  cout << ans << endl;
}