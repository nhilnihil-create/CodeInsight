#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001001;
int main(){
  int N,C,K;
  cin>>N>>C>>K;
  vector<int>T(N);
  for(int i=0;i<N;i++){
    cin>>T[i];
  }
  sort(T.begin(),T.end());
  int bus=0;
  for(int i=0;i<N;){
    bus++;
    int k=i;
    while(T[i]-T[k]<=K&&i-k<C){i++;}
  }
  cout<<bus<<endl;
  return 0;
  }