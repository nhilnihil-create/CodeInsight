#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
#define ll long long 
#define M 1000000007
#define P pair<int,int>
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define rep(i,n) FOR(i,0,n)
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265

int n,k,l;
vector<int> v[300000],w[300000];
int a[300000],b[300000];
map<P,int> mp;

int main(){
  cin>>n>>k>>l;

  rep(i,k){
    int x,y;
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  rep(i,l){
    int x,y;
    cin>>x>>y;
    w[x].push_back(y);
    w[y].push_back(x);
  }
  rep(i,n+1){
    a[i]=i;
    b[i]=i;
  }

  rep(i,n+1){
    queue<int> q;
    q.push(i);
    while(!q.empty()){
      int x = q.front(); q.pop();
      rep(j,v[x].size()){
        if(a[i]!=a[v[x][j]]){
          a[v[x][j]]=a[i];
          q.push(v[x][j]);
        }
      }
    }
  }

  rep(i,n+1){
    queue<int> q;
    q.push(i);
    while(!q.empty()){
      int x = q.front(); q.pop();
      rep(j,w[x].size()){
        if(b[i]!=b[w[x][j]]){
          b[w[x][j]]=b[i];
          q.push(w[x][j]);
        }
      }
    }
  }

  rep(i,n+1){
    mp[P(a[i],b[i])]++;
  }
  FOR(i,1,n+1){
    if(i!=1) cout<<' ';
    cout<<mp[P(a[i],b[i])];
  }
  cout<<endl;

}
  
