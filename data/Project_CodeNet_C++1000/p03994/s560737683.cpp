#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
vector<pair<int64_t,int64_t>>prime_factorize(int64_t x){
  vector<pair<int64_t,int64_t>>p;
  for(int64_t i=2;i*i<=x;i++){
    int cnt=0;
    if(x%i==0){
    while(x%i==0){cnt++;x/=i;}
    p.push_back(make_pair(i,cnt));
    }
  }
  if(x!=1){p.push_back(make_pair(x,1));}
  return p; 
}

int main() {
  string s;
  cin>>s;
  int K;
  cin>>K;
  int n=s.size();
  vector<int>sp(n);
  for(int i=0;i<n;i++){
    sp[i]=26-(s[i]-'a');
  }
  for(int i=0;i<n;i++){
    if(sp[i]<=K){
      if(s[i]>(char)((s[i]-'a'+sp[i])%26+'a')){
      s[i]='a';K-=sp[i];}
      }
  }
  if(K>0){
    s[n-1]=(char)((s[n-1]-'a'+K)%26+'a');
  }
  cout<<s<<endl;
  return 0;
}