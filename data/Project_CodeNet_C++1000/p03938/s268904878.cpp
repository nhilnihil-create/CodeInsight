# include <bits/stdc++.h>
using namespace std;

/*
  idea :
  a = n, 2n, 3n, ..., n*n
  b = (n+1)n, (n+1)(n-1), (n+1)(n-2), ..., (n+1)1
  this makes a ascending and b descending

  and this forms :
  ai+bi becomes a pattern : x, x-1, x-2, ..., n*n + (n+1)

  then starting from p1, add the value of 
  a(p1) becomes x+1
  a(p2) becomes x+2
  ...
*/

int main(){
  int n, a[60005], b[60005], p[60005], val[60005];
  cin >> n;
  for(int i=1; i<=n; i++){
    cin >> p[i];
    val[p[i]] = p[i] + i-1;
  }

  for(int i=1; i<=n; i++){
    a[i] = i * n + val[i];
    b[i] = (n+1) * ((n+1) - i);
  }

  for(int i=1; i<=n; i++) cout << a[i] << " "; cout << endl;
  for(int i=1; i<=n; i++) cout << b[i] << " "; cout << endl;

  return 0;
}