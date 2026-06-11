#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int i;
  cin >> s;
  for(i=0;i<19;i++){
    if(i==5||i==13){
      cout << " ";
    }else{
      cout << s.at(i);
    }
  }
  cout << endl;
}