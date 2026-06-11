#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  string S,T="gp";
  cin>>S;
  int k=0;
  for(int i=0;i<S.size();i++){
    if(S[i]<T[i%2])
      k++;
    else if(S[i]>T[i%2])
      k--;
  }
  cout<<k<<endl;
}