#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,K;cin>>N>>K;
  vector<int>A(K);
  for(int i=0;i<K;i++)cin>>A[i];
  for(int i=N;;i++){
    string S=to_string(i);
    bool b=false;
    for(int j=0;j<S.size();j++){
      for(int k:A)
        if(S.at(j)=='0'+k){b=true;break;}
      if(b)break;
      if(j==S.size()-1){cout<<i<<endl;return 0;}
    }
  }
}