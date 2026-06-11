#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  
  vector<int> b(n,0), c(n,0);
  rep(i,n)
  {
    b[i] += (i+1)*20202;
    c[i] += (n-i)*20202;
    b[a[i]-1] += i;
    c[a[i]-1] += i;
  }
  
  rep(i,n) cout << b[i] << ((i == n-1)? "\n" : " ");
  rep(i,n) cout << c[i] << ((i == n-1)? "\n" : " ");
  //rep(i,n) cout << b[i] + c[i] << " "; cout << endl;
  
  return 0;
}
  