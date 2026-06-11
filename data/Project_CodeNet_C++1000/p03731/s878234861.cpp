#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  int n,t;
  cin>>n>>t;
  vector<int> ComeTime(n+1);
  rep(i,n) cin>>ComeTime[i];
  ComeTime[n]=1e10;
  int SumTime=0;
  rep(i,n){
    int WhileTime=ComeTime[i+1]-ComeTime[i];
    SumTime+=min(t,WhileTime);
    //cout<<SumTime<<endl;
  }
  cout<<SumTime<<endl;
}