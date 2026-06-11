#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int mx = max(a,c);
  int mn = min(b,d);

  cout << max(0, mn - mx) << endl;
  return 0;
}