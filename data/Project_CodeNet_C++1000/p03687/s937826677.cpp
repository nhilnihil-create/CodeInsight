#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin>>S;
  int N=S.size();
  vector<int> p(26,0);
  vector<int> q(26,-1);
  for(int i=0;i<N;i++){
    int a=S[i]-'a';
    p[a]=max(p[a],i-q[a]-1);
    q[a]=i;
  }
  int Z=N;
  for(int i=0;i<26;i++){
    p[i]=max(p[i],N-1-q[i]);
    Z=min(Z,p[i]);
  }
  cout<<Z<<endl;
  
}