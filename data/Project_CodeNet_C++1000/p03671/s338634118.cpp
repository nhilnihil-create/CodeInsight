#include<bits/stdc++.h>
using namespace std;

#define ll long long

signed main()
{
  int a,b,c;
  cin >> a >> b >> c;
  if(a==b&&b==c) cout<< a+b << "\n";
  else if(a+b < b+c && a+b < a+c) cout<< a+b << "\n";
  else if(b+c < a+b && b+c < a+c) cout<< b+c << "\n";
  else if(a+c < a+b && a+c < b+c) cout<< a+c << "\n";
}