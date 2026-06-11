#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  map<int,int> m;
  rep(i,0,n){
    int a;
    cin>>a;
    m[a]++;
  }
  int cur=0;
  for(auto p:m){
    cur+=p.second-1;
  }
  if(cur%2==0){
    cout<<m.size()<<endl;
  }
  else{
    cout<<m.size()-1<<endl;
  }
}