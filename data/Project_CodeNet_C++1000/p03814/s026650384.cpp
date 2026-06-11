#include <iostream>
using namespace std;
int main(void){
   string s;
   cin >> s;
   int a = 0;
   for(int i = 0;i < s.size();i++){
         if(s[i] == 'A'){
               a = i;
               break;
         }
   }
   int z = s.size();
   for(int i = s.size() - 1;i >= 0;i--){
         if(s[i] == 'Z'){
               z = i;
               break;
         }
   }
   cout << z - a + 1 << endl;
}
