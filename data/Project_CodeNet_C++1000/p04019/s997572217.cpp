#include <iostream>
using namespace std;
int main(void){
   string S;
   cin >> S;
   int n = 0;
   int s = 0;
   int w = 0;
   int e = 0;
   for(int i = 0;i < S.size();i++){
       switch(S[i]){
             case 'N':
             n++;
             break;
             case 'S':
             s++;
             break;
             case 'W':
             w++;
             break;
             case 'E':
             e++;
             break;
       }  
   }
   
   if(
         ((n > 0 && s > 0) || (n == 0 && s == 0)) &&
         ((w > 0 && e > 0) || (w == 0 && e == 0))
         
      ){
            cout << "Yes" << endl;
      }else{
            cout << "No" << endl;
      }
}
