#include <bits/stdc++.h>

using namespace std;
 
int main() {
  int n;
  int length;
  string a; 
  
  cin >> n;
  cin >> length;
  cout <<std::string(length+2, '#')<<endl;
  for(int i=0;i<n;i++){
    cin >>a;
    cout<<"#"<<a<<"#"<<endl;
  }
    cout <<std::string(length+2, '#')<<endl;


  }     

