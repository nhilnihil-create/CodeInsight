#include<bits/stdc++.h>
 using namespace std;
#define  ll long long

 int main() {
     string s ;
     cin >> s ;
     string ans ="" ;
     for (int i = 0; i < s.size() ; ++i) {
         if(s[i]=='1') ans+="1";
         else if(s[i]=='0') ans+="0";
         else if(ans.size()>=1) ans.pop_back();
     }
     cout<<ans<<endl;
 }