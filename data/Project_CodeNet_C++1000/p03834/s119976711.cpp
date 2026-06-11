#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
int main(void){
   string s ;
   cin >> s ;
   size_t n = s.length() ;
   for(int i = 0 ; i < n ; i++){
      if(s[i] == ','){
          cout << " " ;
      }else{
          cout << s[i] ;
      }
   }
   cout << endl;
   return 0 ;
}