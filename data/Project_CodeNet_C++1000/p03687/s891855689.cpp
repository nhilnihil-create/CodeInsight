#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(void){
    
   string s;
   cin >> s;
   
   int n = (int)s.size();
   
   int ans = 99999;
   
   for (char x = 'a'; x <= 'z'; x++){
       
       int count = 0;
       int temp = 0;
       
       s += x;
       
       for (int i = 0; i < n+1; i++){
           
           if (s[i] == x){
               temp = max(temp,count);
               count = 0;
           }
           else{
               count++;
           }
       }
       
       s = s.substr(0,n);
       ans = min(ans, temp);
   }
    
    cout << ans << endl;
}
