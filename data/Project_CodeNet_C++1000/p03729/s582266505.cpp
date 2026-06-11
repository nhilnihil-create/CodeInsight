#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());
#define vecmin(A) *min_element(A.begin(),A.end());
#define vecmax(A) *max_element(A.begin(),A.end());
typedef long long ll;

int main(){
  string a,b,c;
  cin >> a >> b >> c;
  int p,q,r;
  p = a.size()-1;
  q = b.size()-1;
  r = c.size()-1;
  if(a[p] == b[0] && b[q] == c[0]) cout << "YES" << endl;
  else cout << "NO" << endl;
}