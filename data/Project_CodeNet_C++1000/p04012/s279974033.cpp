#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
 
int main(){
  string w;
  cin>>w;
  map<char,int> m;
  rep(i,w.length()) m[w[i]]++;
  bool ja=true;
  for(auto x:m){
    if(x.second%2==1){
      ja=false;
    }
  }
  if(ja){
    cout<<"Yes"<<endl;
    return 0;
  }
  cout<<"No"<<endl;
}   