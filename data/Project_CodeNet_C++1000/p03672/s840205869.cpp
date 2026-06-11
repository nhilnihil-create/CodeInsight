#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vin=vector<int>;
const int inf=1e9+7;
const ll INF=1e18;


bool guu(string s){
  bool ans=true;
  int n=s.size();
  rep(i,n/2){
  // cout<<s[i]<<s[n/2+i]<<endl;
    if(s[i]!=s[n/2+i]){
      ans=false;
      break;
    }
  }
      return ans;
}



int main() {
  string s;
  cin>>s;
  if(s.size()%2==0){
    s.pop_back();s.pop_back();
  }
  else{
   s.pop_back(); 
  }
  while(!guu(s)){
   s.pop_back(); s.pop_back(); 
  }
  cout<<s.size()<<endl;
}