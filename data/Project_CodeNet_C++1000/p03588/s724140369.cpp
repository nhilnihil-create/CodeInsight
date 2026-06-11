#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  int a, b, maxa = 0, point;
  for(int i = 0; i < n; i++){
   cin >> a >> b; 
   if(a > maxa){
     maxa = a;
     point = b;
   }
  }
  
  cout << maxa + point << '\n';
}