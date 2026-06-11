#include <bits/stdc++.h>
using namespace std;
int main(){
  int a, b, c, d;
  int ans = 0;
  cin >> a >> b >> c >> d;
  for(int i=0; i<=100; ++i){
    if(i >= a && i >= c && i <= b && i <= d) ++ans;
  }
  cout << (ans == 0 ? 0 : --ans) << endl;
}