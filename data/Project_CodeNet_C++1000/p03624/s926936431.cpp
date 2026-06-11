#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
   string S;
   cin >> S;
   int size = S.size() ;
   vector<int> alphabet(26);  // 0 tag
   for(int i=0;i<size;i++){
       int num = S[i] -'a' ;  // 各alphabet を番号管理
       alphabet.at(num) = 1;  // 1 tag
   }
   char min_char;
   bool judge = false;
   for(int i=0;i<26;i++){
       if(alphabet.at(i) ==  0){
            min_char = i + 'a';
            judge = true;
           break;
       }
       else if(i == 25){
           cout << "None" << endl;
       }
   }
   if(judge){
       cout << min_char << endl;
   }
}