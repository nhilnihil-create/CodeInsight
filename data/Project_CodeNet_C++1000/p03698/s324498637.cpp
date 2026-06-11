#include<iostream>
#include<string>
using namespace std;
 
int main(){
  string s, ans;
  cin >> s;
  int a;
  a = s.size();
  for(int i = 0;i < a;i++){
    for(int j = 0;j < a;j++){
      if(i != j){
    if(s.at(i) == s.at(j)){
      ans = "no";
      break;
    }
   }
       }
    if(ans == "no"){
      break;
    }
     }
  if(ans != "no"){
    ans = "yes";
  }
  cout << ans;
    }