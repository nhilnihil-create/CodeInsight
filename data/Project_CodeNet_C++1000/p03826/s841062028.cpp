#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
using P = pair <int, int>;


int main() {
     int a,b,c,d;
     cin >>a>>b>>c>>d;
     ll A,B;
     A = a*b;
     B = c*d;
     if(A>B){
         cout << A << endl;
         return 0;
     }
     else {
         cout << B << endl;
         return 0;
     }
  }