#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  string s;
  cin>>n>>s;
  s=' '+s;
  vector<char> ans(n+2);
  ans[1]='S',ans[2]='S';
  FOR(i,2,n+1){
    if(s[i]=='o'){
      if(ans[i]=='S' && ans[i-1]=='S') ans[i+1]='S';
      if(ans[i]=='S' && ans[i-1]=='W') ans[i+1]='W';
      if(ans[i]=='W' && ans[i-1]=='S') ans[i+1]='W';
      if(ans[i]=='W' && ans[i-1]=='W') ans[i+1]='S';
    }else{
      if(ans[i]=='S' && ans[i-1]=='S') ans[i+1]='W';
      if(ans[i]=='S' && ans[i-1]=='W') ans[i+1]='S';
      if(ans[i]=='W' && ans[i-1]=='S') ans[i+1]='S';
      if(ans[i]=='W' && ans[i-1]=='W') ans[i+1]='W';
    }
  }
  if((s[1]=='o' && ans[2]==ans[n])||((s[1]=='x' && ans[2]!=ans[n]))){
    if(ans[1]==ans[n+1]){
      FOR(i,1,n+1) cout<<ans[i];
      cout<<endl;
      return 0;
    }
  }
  ans[1]='S',ans[2]='W';
  FOR(i,2,n+1){
    if(s[i]=='o'){
      if(ans[i]=='S' && ans[i-1]=='S') ans[i+1]='S';
      if(ans[i]=='S' && ans[i-1]=='W') ans[i+1]='W';
      if(ans[i]=='W' && ans[i-1]=='S') ans[i+1]='W';
      if(ans[i]=='W' && ans[i-1]=='W') ans[i+1]='S';
    }else{
      if(ans[i]=='S' && ans[i-1]=='S') ans[i+1]='W';
      if(ans[i]=='S' && ans[i-1]=='W') ans[i+1]='S';
      if(ans[i]=='W' && ans[i-1]=='S') ans[i+1]='S';
      if(ans[i]=='W' && ans[i-1]=='W') ans[i+1]='W';
    }
  }
  if((s[1]=='o' && ans[2]==ans[n])||((s[1]=='x' && ans[2]!=ans[n]))){
    if(ans[1]==ans[n+1]){
      FOR(i,1,n+1) cout<<ans[i];
      cout<<endl;
      return 0;
    }
  }
  ans[1]='W',ans[2]='S';
  FOR(i,2,n+1){
    if(s[i]=='o'){
      if(ans[i]=='S' && ans[i-1]=='S') ans[i+1]='S';
      if(ans[i]=='S' && ans[i-1]=='W') ans[i+1]='W';
      if(ans[i]=='W' && ans[i-1]=='S') ans[i+1]='W';
      if(ans[i]=='W' && ans[i-1]=='W') ans[i+1]='S';
    }else{
      if(ans[i]=='S' && ans[i-1]=='S') ans[i+1]='W';
      if(ans[i]=='S' && ans[i-1]=='W') ans[i+1]='S';
      if(ans[i]=='W' && ans[i-1]=='S') ans[i+1]='S';
      if(ans[i]=='W' && ans[i-1]=='W') ans[i+1]='W';
    }
  }
  if((s[1]=='o' && ans[2]!=ans[n])||((s[1]=='x' && ans[2]==ans[n]))){
    if(ans[1]==ans[n+1]){
      FOR(i,1,n+1) cout<<ans[i];
      cout<<endl;
      return 0;
    }
  }
  ans[1]='W',ans[2]='W';
  FOR(i,2,n+1){
    if(s[i]=='o'){
      if(ans[i]=='S' && ans[i-1]=='S') ans[i+1]='S';
      if(ans[i]=='S' && ans[i-1]=='W') ans[i+1]='W';
      if(ans[i]=='W' && ans[i-1]=='S') ans[i+1]='W';
      if(ans[i]=='W' && ans[i-1]=='W') ans[i+1]='S';
    }else{
      if(ans[i]=='S' && ans[i-1]=='S') ans[i+1]='W';
      if(ans[i]=='S' && ans[i-1]=='W') ans[i+1]='S';
      if(ans[i]=='W' && ans[i-1]=='S') ans[i+1]='S';
      if(ans[i]=='W' && ans[i-1]=='W') ans[i+1]='W';
    }
  }
  if((s[1]=='o' && ans[2]!=ans[n])||((s[1]=='x' && ans[2]==ans[n]))){
    if(ans[1]==ans[n+1]){
      FOR(i,1,n+1) cout<<ans[i];
      cout<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}