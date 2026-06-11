#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;
ll n,m,r;
vector<bool>check;
vector<ll>rr;
vector<vector<ll>>w(205,vector<ll>(205,10e6));
ll res=10e9;
ll kari=0;
ll ha=0;
void dfs(ll v){
  check[v]=true;
  ll count=0;
  for(int i=0; i<r; i++){
    if(check[rr[i]]) count++;
  }
  if(count==r){
    //cout << ha << "  " << kari << endl;
    res=min(res,kari);
  }
  
  for(int i=0; i<r; i++){
    ll u=rr[i];
    if(check[u])continue;
    kari+=w[v][u];
    dfs(u);
    kari-=w[v][u];
  }
  
  check[v]=false;
  
}

int main(){
  cin >> n >> m >> r;
  check.resize(n);
  rr.resize(r);
  
  for(int i=0; i<r; i++){
    cin >> rr[i];
    rr[i]--;
    //cout << rr[i] << endl;
  }
  
  for(int i=0; i<m; i++){
    ll a,b,c;
    cin >> a >> b >> c;
    a--;
    b--;
    w[a][b]=c;
    w[b][a]=c;
  }
  
  //for(int i=0; i<n; i++) w[i][i]=0;
  
  for(int k=0; k<n; k++){
    for(int i=0; i<n; i++){
     for(int j=0; j<n; j++){
       w[i][j]=min(w[i][j],w[i][k]+w[k][j]);
     }
    }
  }
  
  ll ans=10e9;
  for(int i=0; i<r; i++){
    for(int j=0; j<r; j++){
      check[rr[j]]=false;
    }
    res=10e9;
    kari=0;
    dfs(rr[i]);
    ans=min(ans,res);
    ha++;
  }
  
  cout << ans << endl;
  
}
  
  
  
