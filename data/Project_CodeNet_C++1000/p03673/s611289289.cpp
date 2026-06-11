#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main() {
  int n;
  cin >>n;
  vector<int> g={},h={};
  rep(i,n){
    int q;
    cin >>q;
    if(i%2==0){h.push_back(q);}else{g.push_back(q);}
  }
  if(n%2==1){
    for(int i=h.size()-1;i>=0;i--){
      cout << h[i] << " ";
    }
    for(int i=0;i<g.size();i++){
      cout << g[i] << " ";
    }
  }else{
    for(int i=g.size()-1;i>=0;i--){
      cout << g[i] << " ";
    }
    for(int i=0;i<h.size();i++){
      cout << h[i] << " ";
    }
  }
  cout << endl;
}