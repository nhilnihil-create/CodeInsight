#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;cin>>S;
  vector<bool> A(26,false);
  bool isyes=true;
  int l=S.size();
  for(int i=0;i<l;i++){
    if(!A.at(S.at(i)-'a')) A.at(S.at(i)-'a')=true;
    else isyes=false;
  }
  cout<<(isyes?"yes":"no")<<endl;
}
    