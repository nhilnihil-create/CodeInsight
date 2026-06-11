#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  string s;
  cin>>n>>s;
  int cur=0;
  int wor=0;
  rep(i,0,n){
    if(s[i]=='(') cur++;
    else cur--;
    wor=min(cur,wor);
  }
  rep(i,0,-wor){
    cout<<'(';
  }
  cout<<s;
  rep(i,0,cur-wor){
    cout<<')';
  }
  cout<<endl;
}