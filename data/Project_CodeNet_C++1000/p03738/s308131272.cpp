#include <bits/stdc++.h>
using namespace std;

int main(void){
    
   string a,b;
   cin >> a >> b;
   if(a.size() > b.size()){
       cout << "GREATER" << endl;
   }
   else if(a.size() < b.size()){
       cout << "LESS" << endl;
   }
   else{
       string ans = "EQUAL";
       int size = a.size();
       
       for(int i=0;i<size;i++){
           if(a[i] > b[i]){
               ans = "GREATER";
               break;
           }
           else if(a[i] < b[i]){
               ans = "LESS";
               break;
           }
       }
       cout << ans << endl;
   }
}