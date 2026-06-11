#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin>>S;
  int N=S.size();
  int Z=0;
  for(int i=0;i<N;i++){
    if(S[i]=='p'){
      Z++;
    }
  }
  cout<<N/2-Z<<endl;
}