#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main()
{
  int x,a,b;
  cin >> x >> a >> b;
  if(a>=b){cout << "delicious";}
  else if((b-a)<=x){cout << "safe";}
  else{cout << "dangerous";} 
}