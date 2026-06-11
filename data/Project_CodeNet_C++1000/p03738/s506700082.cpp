#include<bits/stdc++.h>
using namespace std;

int main(){
  string a,b; cin >> a >> b;
  if(a==b){
    cout << "EQUAL" << endl;  
  } else if(a.size()==b.size()){
    for(int i=0; i<a.size(); i++){
      if(a[i]==b[i]) continue;
      else {
        cout << ( a[i]>b[i] ? "GREATER" : "LESS" ) << endl;
        break;
      }
    }
  } else {
    cout << ( a.size()>b.size() ? "GREATER" : "LESS" ) << endl;  
  }
  return 0;
}