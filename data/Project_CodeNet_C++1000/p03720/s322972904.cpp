#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define rep(i,n) for(int i=0; i<n; i++)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてから使う
#define INF 2147483647
#define LLINF 9223372036854775807LL

int main(){
  int n,m; cin>>n>>m;
  vector<int>Ans(n+1,0); //Ans[0]は使わない
  rep(i,m){
    int a,b; cin>>a>>b;
    for (int j=1; j<=n; j++){
      if (a==j) Ans[j]++;
      if (b==j) Ans[j]++;
    }
  }
  for (int i=1; i<=n; i++) cout << Ans[i] << endl;
}