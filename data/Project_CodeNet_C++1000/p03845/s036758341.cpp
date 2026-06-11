#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define all(v) v.begin(),v.end()
#define ll long long int
#define  IOS    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll MOD=1e9+7;

void solve(){
   int n;
   cin >> n;
   vector<int>v(n);
   ll sum=0;
   for(int i=0;i<n;i++)cin >> v[i],sum+=v[i];
   int m;
   cin >> m;
   for(int i=0;i<m;i++){
     int a,b;
     cin >> a >> b;
      cout << sum-v[a-1]+b<<'\n';
   }
}


int main(){
  IOS
     solve();
}
// integer overflow
// remember to clear visited array
// take input as vector<string> while using grid
