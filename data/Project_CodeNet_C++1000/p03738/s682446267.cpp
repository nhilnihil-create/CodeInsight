#include <iostream>
#include <string>
using namespace std;

int main()
{
  string a, b;
  cin >> a >> b;
  
  if(a.length() > b.length()){
    cout << "GREATER" << endl;
  }else if(a.length() < b.length()){
    cout << "LESS" << endl;
  }else{
    bool equal = true;
    for(unsigned int i = 0; i < a.length(); ++i){
      if(a[i] > b[i]){
        cout << "GREATER" << endl;
        equal = false;
        break;
      }else if(a[i] < b[i]){
        cout << "LESS" << endl;
        equal = false;
        break;
      }
    }
    if(equal) cout << "EQUAL" << endl;
  }
}