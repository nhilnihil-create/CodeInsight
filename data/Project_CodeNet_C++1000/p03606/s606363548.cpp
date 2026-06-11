#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int keisansu;
   
  cin >> keisansu;
  
  int a;
  int b;
  int count=0;
  for (int i = 0; i < keisansu; i++) {
    cin >> a;
    cin >> b;
    count+=b-a+1;

  }
  cout<<count;;
}