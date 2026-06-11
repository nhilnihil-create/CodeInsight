#include <bits/stdc++.h>
using namespace std;

template<typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}

signed main(){
  string s;cin>>s;
  set<char> se;for(char p:s)se.insert(p);
  if(se.count('N')^se.count('S'))fin("No");
  if(se.count('E')^se.count('W'))fin("No");
  fin("Yes");
}
