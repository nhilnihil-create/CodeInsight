#include <bits/stdc++.h>
#define ll long long
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const ll INF=(ll)1e9;
const ll MOD=(ll)1e9+7;
vector<int> dx={1,0,-1,0},dy={0,1,0,-1};

int main(){
  int N;
  ll ans=1;
  cin>>N;
  map<ll,ll> m;
  for(int i=2;i<=N;i++){
    int num=i;
    for(int j=2;j<=N;j++){
      while(num%j==0){
        m[j]++;
        num/=j;
      }
    }
  }
  for(int i=2;i<=N;i++){
    ans*=m[i]+1;
    ans%=MOD;
  }
  cout<<ans<<endl;
}
