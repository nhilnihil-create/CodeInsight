#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;cin>>S;int M=0;
  for(int X=1;X<S.size();X++){
    if(S[X]!=S[X-1])M++;
  }
  cout<<M<<endl;
}