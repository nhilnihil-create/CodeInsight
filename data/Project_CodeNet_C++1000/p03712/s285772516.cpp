#include<bits/stdc++.h>
using namespace std;

int main(){
 int H,W;
  cin >> H >> W;
 vector<string> word(H);
  for(int i;i<H;i++){
    cin >> word.at(i);
  }
  for(int i;i<W+2;i++){
    cout<< '#' ;
  }
  cout << endl;
  for(int i;i<H;i++){
    cout << '#' + word.at(i) + '#'<<endl;
  }
   for(int i;i<W+2;i++){
    cout<< '#' ;
  }
    
}