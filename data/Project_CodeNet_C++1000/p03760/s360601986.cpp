#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 
  string O,E;
  cin>>O>>E;

  string out;
  int cnt_e=0,cnt_o=0;
  for(int i=0;i<O.size()+E.size();i++){
    if(i%2!=0){
      cout<<E.at(cnt_o);
      cnt_o++;
    }
    else{
      cout<<O.at(cnt_e);
      cnt_e++;
    }
  }

    cout<<endl;
  return 0;
}