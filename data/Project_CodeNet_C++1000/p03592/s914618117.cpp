#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i < (ll)(n); i++)
#define INF 10000000000
#define MOD 10007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
  int N,M,K;cin>>N>>M>>K;
  if(K%N==0||K%M==0){
    cout<<"Yes"<<endl;
    return 0;
  }
  else{
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= M; j++){
        int tmp = M*i + N*j - 2*i*j;
        if(K==tmp){
          cout<<"Yes"<<endl;
          return 0;
        }
      }
    }
  }
  cout<<"No"<<endl; 
}
