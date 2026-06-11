#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
#define MAX 1000010
#define MOD 1000000007
  
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
  int H,W; cin>>H>>W;
  int N; cin>>N;
  queue<int> Q;
  rep1(i,N+1){
    int a;  cin>>a;
    rep(j,a)Q.push(i);
  }
  vector<vector<int>> res(H,vector<int> (W));
  rep(i,H){
    if(i%2==0){
      rep(j,W){
        int q = Q.front();
        Q.pop();
        res.at(i).at(j)=q;
      }
    }else{
      for(ll j = W-1; j >= 0; j--){
        int q = Q.front();
        Q.pop();
        res.at(i).at(j)=q;        
      }
    }
  }
  rep(i,H){
    rep(j,W){
      cout<<res.at(i).at(j)<<" ";
    }
    cout<<endl;
  }
}