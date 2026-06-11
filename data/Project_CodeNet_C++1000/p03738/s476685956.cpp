#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int main(void){
   string a;
   string b;
   cin >> a >> b;
   
   if(a.size() > b.size()){
         cout << "GREATER" << endl;
   }else if(a.size() < b.size()){
         cout << "LESS" << endl;
   }else{// a.size()  == b.size()
         for(int i = 0;i < a.size();i++){
               if(a[i] == b[i])continue;
               if(a[i] < b[i]){
                     cout << "LESS" << endl;
                     return 0;
               }else{
                     cout << "GREATER" << endl;
                     return 0;
               }
         }
         cout << "EQUAL" << endl;
   }
}
