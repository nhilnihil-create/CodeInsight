#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007
#define MAX 2100000
#define INF 1001000000
using Graph=vector<vector<int>>;

int main(){
  int N;
  cin>>N;
  vector<int> L(2*N);
  for(int i=0;i<2*N;i++){
    cin>>L.at(i);
  }
  sort(L.begin(),L.end());

  int ans=0;
  for(int i=0;i<N;i++){
    ans+=min(L.at(2*i),L.at(2*i+1));
  }
  cout<<ans<<endl;
}
