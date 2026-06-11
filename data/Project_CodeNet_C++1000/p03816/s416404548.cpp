#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
   int n,ans=0;
   cin >> n;
   int a[n];
   map<int,int> mp;
   rep(i,n){
       cin >> a[i];
       mp[a[i]]++;
   }
   for(auto i:mp){
       if(i.second>1) ans += (i.second-1);
   }
   if(ans%2) cout << mp.size()-1 << endl;
   else cout << mp.size() << endl;
}