#include <iostream>
#include <vector>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  if(a==2||b==2)cout << "No";
  else if(a==4||a==6||a==9||a==11){
    if(b==4||b==6||b==9||b==11){
      cout << "Yes";
    }
    else cout << "No";
  }
  else{
    if(b==4||b==6||b==9||b==11){
      cout << "No";
    }
    else cout << "Yes";
  }
}
