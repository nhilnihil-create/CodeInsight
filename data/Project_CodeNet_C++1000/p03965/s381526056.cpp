#include <bits/stdc++.h>
#define ll long long
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};

int main(){
  string S;
  cin>>S;
  ll ans=0;
  for(ll i=0;i<S.size();i++){
    if(i%2==0){
      if(S[i]=='p') ans--;
    }else{
      if(S[i]=='g') ans++;
    }
  }
  cout<<ans<<endl;
}