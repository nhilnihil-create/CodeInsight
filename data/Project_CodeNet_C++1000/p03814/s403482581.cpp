#include <bits/stdc++.h>
#include<iostream>
using namespace std;
 
int main() {
   string s;
   cin >>s;
   bool a,b;
   a = true;
   int ans,A,Z(0);

   for(int i=0;i < s.length();i++){
       if(s.at(i)== 'A' && a){
           a = false;
           A = i;
       }
       if(s.at(i) == 'Z'){
           Z = i;
       }

   }
   cout << abs(A - Z)+1;
}
   