#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll ai, ao, at, aj, al, as, az;
  cin >> ai >> ao >> at >> aj >> al >> as >> az;
  ll res0 = 0, res1 = 0;
  ll bi = ai, bo = ao, bj = aj, bl = al;
  if (bi > 0 && bj > 0 && bl > 0) {res1+=3; bi--; bj--; bl--;}
  res1 += (2*(bi/2) + 2*(bj/2) + 2*(bl/2) + bo);
  res0 += (2*(ai/2) + 2*(aj/2) + 2*(al/2) + ao);
  
  cout << max(res0,res1) << endl; 
}