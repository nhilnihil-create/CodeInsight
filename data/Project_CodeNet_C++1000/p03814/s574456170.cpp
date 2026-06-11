#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

  //initialization
  string s;
  int start, end;
  int i=0;
  //input
  cin >> s;
  
  //output
  while(true){
    if(s[i] == 'A'){
      start = i;
      break;
    }
    i++;
  }
  
  i = 0;
  while(true){
    if(s[s.size()-i] == 'Z'){
      end = s.size() - i;
      break;
    }
    i++;
  }
 //  cout << start << " " << end << "\n"; 
  cout << end - start + 1 << "\n";

}
