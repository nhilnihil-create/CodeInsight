#include<bits/stdc++.h>
using namespace std;
int main(){
  int H,W;
  cin >>H>>W;
  vector<char> vec(W+2);
  for(int i=0;i<W+2;i++){
    vec.at(i)='#';
  }
   for(int i=0;i<W+2;i++){
  cout << vec.at(i);
  }
  cout <<endl;
  /*ここまでで一段目の＃を出力*/

 for(int k=0;k<H;k++){
  vector<char> vect(W+2);
    vect.at(0)='#';
    vect.at(W+1)='#';
  for(int i=1;i<W+1;i++){
    cin >>vect.at(i);
  }
    for(int i=0;i<W+2;i++){
      cout <<vect.at(i);
  }
   cout <<endl;
  
}
  /*ここから最後の談の＃を出力する*/
 for(int i=0;i<W+2;i++){
   cout <<vec.at(i);
 }
  cout <<endl;
  
}