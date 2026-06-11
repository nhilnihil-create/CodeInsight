#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)


int  main(){
  string s,t; cin>>s>>t;
  if(s.size()==t.size()){
    rep(i,s.size())cout<<s.at(i)<<t.at(i);
  }
  else{
    rep(i,t.size())cout<<s.at(i)<<t.at(i);
    cout<<s.at(s.size()-1);
  }
}