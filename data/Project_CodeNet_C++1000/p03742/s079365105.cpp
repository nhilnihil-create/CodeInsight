#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
int main()
{
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  long long a, b;
  cin >> a >> b;
  if(abs(a - b) <= 1){
    cout << "Brown";
  }else{
    cout << "Alice";
  }
}
