#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b;
  cin>>a>>b;
  vector<string> v(b+2,"#");  
  for(int k=0;k<b+2;k++){
  cout<<v.at(k);
  }
  cout<<endl;
   
  for(int i=0;i<a;i++){
    vector<char> w(b+2);
    w.at(0)='#';
    cout<<w.at(0);
    for(int j=1;j<b+1;j++){
      cin>>w.at(b);
      cout<<w.at(b);
    }
    w.at(b+1)='#';
    cout<<w.at(b+1)<<endl;    
  }
  
  for(int k=0;k<b+2;k++){
  cout<<v.at(k);
  }
  cout<<endl;
    
  
}