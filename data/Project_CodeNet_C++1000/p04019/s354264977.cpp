#include <bits/stdc++.h>
using namespace std;

int main(void){

   string s;
   cin >> s;
   int n = s.size();

   //[+北,-南][+東,-西]
   int ns = 0;
   int ew = 0;
   bool u, d, l, r;
   u = d = l = r = false;

   for(int i=0;i<n;i++){
      switch(s.at(i)){
         case 'N':
            ns++;
            u = true;
            break;
         case 'S':
            ns--;
            d = true;
            break;
         case 'E':
            ew++;
            r = true;
            break;
         case 'W':
            ew--;
            l = true;
            break;
         }
   }
   if(ns == 0 && ew == 0){
      cout << "Yes" << endl;
      return 0;
   }
   if(u && d && r && l)
      cout << "Yes" << endl;
   else if ((u && d && ew == 0) || (ns == 0 && r && l))
      cout << "Yes" << endl;
   else cout << "No" << endl;

   return 0;
}