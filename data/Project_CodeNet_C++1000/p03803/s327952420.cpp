#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main()
{
  int A,B;
  cin >> A >> B;
  if(A==1){A += 13;}
  if(B==1){B += 13;}

  if(A>B){cout << "Alice";}
  else if(B>A){cout << "Bob";}
  else{cout << "Draw";}
}