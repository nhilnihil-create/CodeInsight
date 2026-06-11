#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
ll MOD=1000000007;
const double PI = acos(-1);

int main(){
  int n,m; cin>>n>>m;
  vector<int>city(n,0);
  rep(i,m){
    int a,b; cin>>a>>b;
    a--; b--;
    city[a]++;
    city[b]++;
  }
  rep(i,n) cout << city[i] << endl;
}