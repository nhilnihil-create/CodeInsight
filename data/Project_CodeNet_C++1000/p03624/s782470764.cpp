#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<=(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
 
int main(){
  string S;
  cin>>S;
  sort(all(S));
  string T="abcdefghijklmnopqrstuvwxyz";
  for(int i=0;i<26;i++) {
    bool a=true;
    for(char x:S) {
     if(x==T[i]) {
       a=false;
     }
    }
    if(a) {
      cout<<T[i]<<endl;
      return 0;
    }
  }
  cout<<"None"<<endl;
}