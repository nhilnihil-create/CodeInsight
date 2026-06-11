#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;cin>>S;
  int cnt=0;
  char rc=S[0];
  for(int i=1;i<S.size();i++){
    if(rc!=S[i])cnt++;
    rc=S[i];
  }
  cout<<cnt<<endl;
}
