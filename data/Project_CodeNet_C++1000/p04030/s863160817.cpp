#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void){
   string S;
   cin >> S;
   string ans;
   for(int i=0;i<S.size();i++){
       if(S[i] == '0'){
           ans.push_back('0');
       }
       if(S[i] == '1'){
           ans.push_back('1');
       }
       if(S[i] == 'B'){
           if(!ans.empty()){
               ans.pop_back();
           }
       }
   }
   cout << ans << endl;
}
