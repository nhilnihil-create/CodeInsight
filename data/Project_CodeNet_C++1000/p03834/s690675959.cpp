#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define ll long long int
#define  IOS    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll MOD=1e9+7;

void solve(){
   string s;
   cin >> s;
   cout << s.substr(0,5);
   cout << ' ';
   cout << s.substr(6,7);
   cout << ' ';
   cout << s.substr(6+7+1);
}


int main(){
  IOS
     solve();
}
// integer overflow
// remember to clear visited array
// take input as vector<string> while using grid
