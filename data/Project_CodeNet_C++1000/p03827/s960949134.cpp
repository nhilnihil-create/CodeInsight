#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define ll long long int
#define  IOS    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll MOD=1e9+7;

void solve(){
   int n;
   cin >>n;
   string s;
   cin >> s;
   int ans =0;
   int finalans=0;
   for(int i=0;i<n;i++){
      ans-=(s[i]=='D')-(s[i]=='I');
      finalans=max(ans,finalans);
   }
   cout << finalans;
}


int main(){
  IOS
     solve();
}
// integer overflow
// remember to clear visited array
// take input as vector<string> while using grid
