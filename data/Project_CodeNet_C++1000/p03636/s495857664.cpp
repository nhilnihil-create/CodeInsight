#include<bits/stdc++.h>
using namespace std;
int main(){
string S;
  cin>>S;
  int n=S.size();
  string x=to_string(n-2);
  cout<<S.at(0)+x+S.at(n-1)<<endl;
   return 0;
}