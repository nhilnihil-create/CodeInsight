#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
  ll n, m;
  cin >> n >> m;
  
  if(n >= m/2)
    cout << m/2 << endl;
  else
    cout << n+(m-2*n)/4 << endl;
  return 0;
}
