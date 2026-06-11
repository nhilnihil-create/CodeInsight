#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string s,t;
  cin>>N>>s>>t;
  for(int i=0;i<=N;i++)
    if(s.substr(i,N-i)==t.substr(0,N-i)){
      cout<<N+i<<endl;
      return 0;
    }
}