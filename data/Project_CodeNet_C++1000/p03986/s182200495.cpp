#include <iostream>
#include <vector>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  int a=0,b=0;
  
  for(int i=0;i<s.size();i++){
    
    if(s[i] == 'S'){
       a++;
    }
    
    else{
      b++;
      if(a>0){
        a--;
        b--;
      }
      
    }
    
    
    
  }
     cout << a + b << endl;
}
