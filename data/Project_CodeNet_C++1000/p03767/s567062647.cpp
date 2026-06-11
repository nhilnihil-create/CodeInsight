#include <iostream>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

int main(void){

   ll n;
   cin >> n;
   vector<ll> a(3*n);
   for (int i = 0; i < 3*n;i++)
      cin >> a.at(i);
   sort(a.begin(), a.end());

   ll i = 3 * n - 2;
   ll ans = 0;
   while (n--){
      ans += a.at(i);
      i -= 2;
   }
   cout << ans << endl;
   return 0;
}