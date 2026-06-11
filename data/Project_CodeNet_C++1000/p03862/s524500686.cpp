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
  int N,x;
  cin>>N>>x;
  vector<int>a(N);
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  int64_t sum=0;
  for(int i=0;i<N;i++){
    if(a[i]>x){sum+=(a[i]-x);a[i]=x;}  
  }
  for(int i=0;i<N-1;i++){
    if(a[i]+a[i+1]>x){
      int64_t c=a[i]+a[i+1]-x;
      if(c>=a[i+1]){a[i+1]=0;a[i]-=(c-a[i+1]);}
      else if(c<a[i+1]&&c>=0){a[i+1]-=c;}
      sum+=c;
    }
  }
  cout<<sum<<endl;
  return 0;
}