#include <bits/stdc++.h>
using namespace std;

int main() {
   int n, a, b, pj = 0, po = 0;
   cin >> n >> a >> b;
   string s;
   cin >> s;
//    int o = count(s.begin(), s.end(), 'b');
   int co = 0;

   for(int i = 0; i < n; i++){
       char c = s[i];
       if(c == 'c'){
           cout << "No" << endl;
       } else if(c == 'a'){
          if(pj + po < a + b){
              cout << "Yes" << endl;
              pj++;
          } else{
              cout << "No" << endl;
          }
       } else {
           if((pj + po) < (a + b) && (co + 1) <= b){
               cout << "Yes" << endl;
               po++;
           } else{
               cout << "No" << endl;
           }
           co++;
       }
   }
   return 0;
}
