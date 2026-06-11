#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;cin>>S;
  cout<<(S.size()>=4? (S.substr(0,4)=="YAKI"?"Yes":"No"):"No")<<endl;
}