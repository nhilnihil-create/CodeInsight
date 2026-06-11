#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
signed main()
{
  int x,a,b; cin >> x >> a >> b;
  int A = abs(x-a);
  int B = abs(x-b);
  if(A<B) cout << "A" << "\n";
  else cout << "B" << "\n";
}