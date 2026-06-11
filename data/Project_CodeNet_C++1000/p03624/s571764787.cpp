#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
  string S;
  cin >> S;
  
  sort((S).begin(), (S).end());
  int i=0;
  for(char a='a'; a<='z'; a++){
    int count=0;
    while( true){
      if(S[i] == a) {
       count++;
       i++;
      }else{
       break;
      } //if
    } //while
   
    if(count == 0){
     cout << a  << "\n";
     return 0;
    } //if
  }//for
   
  cout << "None" << "\n";
 }
