#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
const ll INF = 10e9;

int main(){
  string s,t; cin>>s>>t;
  if (s.size() > t.size()){
    cout << "GREATER" << endl;
    return 0;
  }
  else if (t.size() > s.size()){
    cout << "LESS" << endl;
    return 0;
  }
  else{
    if (s>t){
    cout << "GREATER" << endl;
    return 0;
    }
    else if(t>s){
    cout << "LESS" << endl;
    return 0;
    }
    else{
      cout << "EQUAL" << endl;
      return 0;
    }
  }
}