#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using graph = vector<vector<int>>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)


int main() {
  int n,a,b;
  string s;
  cin>>n>>a>>b>>s;
  rep(i,n){
    if(s.at(i)=='a'&&a+b>0){
      cout<<"Yes"<<endl;
      if(a>0){a--;}
      else{b--;}
    }
    else if(s.at(i)=='b'&&b>0){cout<<"Yes"<<endl;b--;}
    else{cout<<"No"<<endl;}
  }
}