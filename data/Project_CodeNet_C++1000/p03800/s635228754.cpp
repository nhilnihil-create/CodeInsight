#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N;
  cin>>N;
  string S;
  cin>>S;
  bool ok;
  string ans;
  ans = "SS";
  for(int i=1;i<N-1;++i){
    if(ans[i]=='S'){
      if(S[i]=='o'){
        ans += ans[i-1];
      }
      else{
        if(ans[i-1]=='S') ans += 'W';
        else ans += 'S';
      }
    }
    else{
      if(S[i]=='o'){
        if(ans[i-1]=='S') ans += 'W';
        else ans += 'S';
      }
      else{
        ans += ans[i-1];
      }
    }
  }
  ok = true;
  if(ans[0]=='S'){
    if(S[0]=='o'){
      if(ans[1]!=ans[N-1]) ok = false;
    }
    else{
      if(ans[1]==ans[N-1]) ok = false;
    }
  }
  else{
    if(S[0]=='o'){
      if(ans[1]==ans[N-1]) ok = false;
    }
    else{
      if(ans[1]!=ans[N-1]) ok = false;
    }
  }
  if(ans[N-1]=='S'){
    if(S[N-1]=='o'){
      if(ans[N-2]!=ans[0]) ok = false;
    }
    else{
      if(ans[N-2]==ans[0]) ok = false;
    }
  }
  else{
    if(S[N-1]=='o'){
      if(ans[N-2]==ans[0]) ok = false;
    }
    else{
      if(ans[N-2]!=ans[0]) ok = false;
    }
  }
  if(ok){
    cout<<ans<<endl;
    return 0;
  }
  ans = "WS";
  for(int i=1;i<N-1;++i){
    if(ans[i]=='S'){
      if(S[i]=='o'){
        ans += ans[i-1];
      }
      else{
        if(ans[i-1]=='S') ans += 'W';
        else ans += 'S';
      }
    }
    else{
      if(S[i]=='o'){
        if(ans[i-1]=='S') ans += 'W';
        else ans += 'S';
      }
      else{
        ans += ans[i-1];
      }
    }
  }
  ok = true;
  if(ans[0]=='S'){
    if(S[0]=='o'){
      if(ans[1]!=ans[N-1]) ok = false;
    }
    else{
      if(ans[1]==ans[N-1]) ok = false;
    }
  }
  else{
    if(S[0]=='o'){
      if(ans[1]==ans[N-1]) ok = false;
    }
    else{
      if(ans[1]!=ans[N-1]) ok = false;
    }
  }
  if(ans[N-1]=='S'){
    if(S[N-1]=='o'){
      if(ans[N-2]!=ans[0]) ok = false;
    }
    else{
      if(ans[N-2]==ans[0]) ok = false;
    }
  }
  else{
    if(S[N-1]=='o'){
      if(ans[N-2]==ans[0]) ok = false;
    }
    else{
      if(ans[N-2]!=ans[0]) ok = false;
    }
  }
  if(ok){
    cout<<ans<<endl;
    return 0;
  }
  ans = "SW";
  for(int i=1;i<N-1;++i){
    if(ans[i]=='S'){
      if(S[i]=='o'){
        ans += ans[i-1];
      }
      else{
        if(ans[i-1]=='S') ans += 'W';
        else ans += 'S';
      }
    }
    else{
      if(S[i]=='o'){
        if(ans[i-1]=='S') ans += 'W';
        else ans += 'S';
      }
      else{
        ans += ans[i-1];
      }
    }
  }
  ok = true;
  if(ans[0]=='S'){
    if(S[0]=='o'){
      if(ans[1]!=ans[N-1]) ok = false;
    }
    else{
      if(ans[1]==ans[N-1]) ok = false;
    }
  }
  else{
    if(S[0]=='o'){
      if(ans[1]==ans[N-1]) ok = false;
    }
    else{
      if(ans[1]!=ans[N-1]) ok = false;
    }
  }
  if(ans[N-1]=='S'){
    if(S[N-1]=='o'){
      if(ans[N-2]!=ans[0]) ok = false;
    }
    else{
      if(ans[N-2]==ans[0]) ok = false;
    }
  }
  else{
    if(S[N-1]=='o'){
      if(ans[N-2]==ans[0]) ok = false;
    }
    else{
      if(ans[N-2]!=ans[0]) ok = false;
    }
  }
  if(ok){
    cout<<ans<<endl;
    return 0;
  }

  ans = "WW";
  for(int i=1;i<N-1;++i){
    if(ans[i]=='S'){
      if(S[i]=='o'){
        ans += ans[i-1];
      }
      else{
        if(ans[i-1]=='S') ans += 'W';
        else ans += 'S';
      }
    }
    else{
      if(S[i]=='o'){
        if(ans[i-1]=='S') ans += 'W';
        else ans += 'S';
      }
      else{
        ans += ans[i-1];
      }
    }
  }
  ok = true;
  if(ans[0]=='S'){
    if(S[0]=='o'){
      if(ans[1]!=ans[N-1]) ok = false;
    }
    else{
      if(ans[1]==ans[N-1]) ok = false;
    }
  }
  else{
    if(S[0]=='o'){
      if(ans[1]==ans[N-1]) ok = false;
    }
    else{
      if(ans[1]!=ans[N-1]) ok = false;
    }
  }
  if(ans[N-1]=='S'){
    if(S[N-1]=='o'){
      if(ans[N-2]!=ans[0]) ok = false;
    }
    else{
      if(ans[N-2]==ans[0]) ok = false;
    }
  }
  else{
    if(S[N-1]=='o'){
      if(ans[N-2]==ans[0]) ok = false;
    }
    else{
      if(ans[N-2]!=ans[0]) ok = false;
    }
  }
  if(ok){
    cout<<ans<<endl;
    return 0;
  }
  cout<<-1<<endl;
}

