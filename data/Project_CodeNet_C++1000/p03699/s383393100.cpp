#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);
int main() {
 int n;
 cin >> n;
 vector<int> s(n);
 rep(i,n) cin >> s.at(i);

 int ans = 0;
 rep(i,n) ans += s.at(i);
 if(ans%10 == 0){
   sort(s.begin(),s.end());
   rep(i,n)if(s.at(i)%10 != 0){
     ans -= s.at(i);
     break;
   }
   if(ans%10 == 0) ans = 0;
 } 
 cout << ans << endl; 
} 