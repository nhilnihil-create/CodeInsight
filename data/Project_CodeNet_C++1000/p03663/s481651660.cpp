
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<complex>
#include<sstream>
#include<climits>

#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int main() {
 ll ub = 1e12-1, lb = 1e11, mid;

 while (ub-lb > 1) {
   mid = (ub+lb)/2;
   cout << '?' << ' ' << mid << endl;
   char c;
   cin >> c;
   if (c == 'Y') ub = mid;
   else lb = mid;
 }

 bool exeption = true;
 ll digit = 1;
 for (ll l = 1; l <= 1e11; l *= 10) {
   cout << "? " << l << endl;
   char c;
   cin >> c;
   if (c == 'N') {
     exeption = false;
     digit = l / 10;
     break;
   }
 }

 if (exeption) {
   for (ll l = 2; l <= 2*1e11; l *= 10) {
     cout << "? " << l << endl;
     char c;
     cin >> c;
     if (c == 'Y') {
       digit = l / 2;
       break;
     }
   }
 }

 ll ans = ub / (1e11 / digit);   

 cout << "! " << ans << endl;

 return 0;
}
