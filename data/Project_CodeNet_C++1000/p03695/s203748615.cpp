#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  int n;cin>>n;
  vector<int> v(n);

  rep(i,n){
    cin>>v.at(i);
    v.at(i)/=400;
  }
    
  set<int> s;
  int c=0;
  rep(i,n){
    if(v.at(i)>=8){c++;}
    else{s.insert(v.at(i));}
  }
  int count=s.size();

  cout<<max(1,count)<<" "<<count+c;
}
      

