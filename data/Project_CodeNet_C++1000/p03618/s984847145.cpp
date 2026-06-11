#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
#define MAX 1000000
#define MOD 1000000007
#define INF 100000000000000

int main(){
  string A;
  cin>>A;
  ll N=A.size();
  map<char,ll> m;
  for(int i=0;i<N;i++){
    if(m.count(A.at(i))==0){
      m[A.at(i)]=0;
    }
    m[A.at(i)]++;
  }
  ll ans=0;
  for(auto x:m){
    ans+=x.second*(N-x.second);
  }
  cout<<ans/2+1<<endl;
}
