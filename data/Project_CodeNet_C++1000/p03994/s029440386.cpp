#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  string S;
  int K;
  cin>>S>>K;
  for(int i=0;i<S.size();i++){
    if(('z'-S[i]+1)%26<=K){
      K-=('z'-S[i]+1)%26;
      S[i]='a';
    }
  }
  S[S.size()-1]='a'+(S[S.size()-1]-'a'+K)%26;
  cout<<S<<endl;
}