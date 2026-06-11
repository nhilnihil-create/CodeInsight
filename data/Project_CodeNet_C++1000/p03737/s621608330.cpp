#include<bits/stdc++.h>
using namespace std;
int main(){
string A,B,C;
  cin>>A>>B>>C;
  string a = A ;
    transform(a.begin(), a.end(), a.begin(), ::toupper);

    string b = B ;
    transform(b.begin(), b.end(), b.begin(), ::toupper);
  
  string c = C ;
    transform(c.begin(), c.end(), c.begin(), ::toupper);

  cout<<a.at(0)<<b.at(0)<<c.at(0)<<endl;

 

  
  
  
  
  

}
