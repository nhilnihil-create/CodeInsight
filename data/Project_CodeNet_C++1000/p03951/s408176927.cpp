#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
int main(){
   int n,ans = 0;cin >>n;
   string s,t;cin >> s >>t;
   if(s==t){
       cout << n;return 0;
   }
   fo(i,n){
       if((s.substr(n-1-i,i+1)==t.substr(0,i+1))&&(i+1 > ans)){
           ans = i+1;
       }
   }
   cout << 2*n -ans;
}

