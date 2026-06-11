#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  long long ans=0;
  int N = S.size();
  
  for(int bit=0;bit<(1<<(N-1));bit++){
    string s="";
    for(int i=0;i<N;i++){
      s+=S.at(i);
      if(bit>>i&1){
        ans+=stoll(s);
        s="";
      }
    }
    ans+=stoll(s);
    s="";
  }
  cout << ans << endl;
}
