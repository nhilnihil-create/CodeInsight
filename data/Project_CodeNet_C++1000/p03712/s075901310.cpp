#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a;
  int b;
  int i,j;
  
  
  // 変数aで入力を受け取る


  cin >> a >> b;
  for(i=0;i<b+2;i++){
    cout << "#";
  }
    cout << endl;
  vector <char> vec(b);
  for(j=0;j<a;j++){
  for (i=0;i<b;i++){
    cin >> vec.at(i);
  }
  cout<<"#";
  for(i=0;i<b;i++){
  cout << vec.at(i);
  }
  cout<< "#"<< endl;
  }
  for(i=0;i<b+2;i++){
    cout << "#";
  }
  cout << endl;
  
}
    
