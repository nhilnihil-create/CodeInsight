#include<bits/stdc++.h>
 using namespace std;
#define  ll long long

 int main() {
     ll n , m ;
     cin >> n >> m;
     vector<string> v;
     while(n--) {
         string s;
         cin >> s;
         v.push_back(s);
     }
     sort(v.begin(),v.end());
     for (int i = 0; i <v.size() ; ++i) {
         cout<<v[i];
     }
; }