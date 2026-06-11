#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,b;
  cin >> n >> a >> b;
  
  int tuuka=0;
  int kaigai=0;
  string s;
  cin >> s;

  for(int i=0; i < s.size(); i++){
    if(s.at(i) == 'c'){
      cout << "No" << endl;
    }
    
    if(s.at(i) == 'a'){
      if(tuuka < a+b){
        cout << "Yes" << endl;
        tuuka++;
      }
      else{
         cout << "No" << endl;
      }
    }
    
    if(s.at(i) == 'b'){
      if(tuuka < a+b && kaigai < b){
        cout << "Yes" << endl;
        tuuka++;
        kaigai++;
      }
      else{
         cout << "No" << endl;
      }
    }
  }
	return 0;
}
