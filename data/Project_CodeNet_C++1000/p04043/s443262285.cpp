#include<bits/stdc++.h>
 using namespace std;
#define  ll long long

 int main() {
   vector<ll>v(3);
   cin >> v[0] >> v[1] >> v[2];
   sort(v.begin(),v.end());
   (v[0]==v[1] && v[0]==5)?cout<<"YES\n":cout<<"NO\n";
 }