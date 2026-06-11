#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
#define MAX 1000010
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
  int N; cin>>N;
  map<int,int> m;
  rep(i,N){
    int a; cin>>a;
    if(m.count(a))m[a]++;
    else m[a]=1;
  }
  int sec = 0;
  for(auto p : m){
    int count = p.second;
    if(count%2==0)sec++;
  }  
  int res = m.size();
  if(sec%2==1||sec==2)res--;
  cout<<res<<endl;
}