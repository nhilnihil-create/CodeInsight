#include <bits/stdc++.h>
using namespace std;

template<typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}

signed main(){
  string s;cin>>s;
  int n=s.size();
  for(int i=0;i<=n/2;i++){
    if(s[i]=='b'&&s[n-1-i]!='d')fin("No");
    if(s[i]=='d'&&s[n-1-i]!='b')fin("No");
    if(s[i]=='p'&&s[n-1-i]!='q')fin("No");
    if(s[i]=='q'&&s[n-1-i]!='p')fin("No");
  }
  fin("Yes");
}
