#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using pii = pair<int, int>;

int main() {
  string s; cin>>s;
  int c=0;
  rep(i,s.size()-1){
    if(s.at(i)!=s.at(i+1)){c++;}
  }
  cout<<c<<endl;
}

