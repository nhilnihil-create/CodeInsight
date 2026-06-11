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
  int n=s.size();
  int64_t ans=0;
  for(int p=0;p<(1<<n-1);p++){
    int64_t r=0,sum=0;
    for(int i=0;i<n-1;i++){
      string t=s.substr(r,i-r+1);
      if((p>>i)&1){sum+=stoll(t);r=i+1;}
     // cout<<t<<endl;
    }
    sum+=stoll(s.substr(r));
    ans+=sum;
  }
  cout<<ans<<endl;
  return 0;
}
