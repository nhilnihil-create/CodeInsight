#include<iostream>
using namespace std;
int main(void){
  int a,b;
  string s;
  cin >> a >> b;
  for(int i = 1;i <= a;i++){
    for(int j = 0;j < b;j++){
      cin >> s;
      if(s == "snuke"){
        cout << (char)('A'+j) << i; 
      }
    }
  }
}
