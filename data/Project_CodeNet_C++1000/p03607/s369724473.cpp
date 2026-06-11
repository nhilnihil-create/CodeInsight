#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef vector<int> vec;

int main(){
  int n,t;cin>>n;
  set<int> a;
  
  rep(i,n){
    cin>>t;
    if(a.count(t))a.erase(t);
    else a.insert(t);
  }
  cout<<a.size()<<endl;
  
}