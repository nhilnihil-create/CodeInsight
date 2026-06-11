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

int n;
int a[400][400];
map<P,int> m;

bool search(){
  rep(k,n){
    rep(i,n){
      rep(j,n){
        if(i==j||i==k||j==k) continue;
        if(a[i][j]>a[i][k]+a[k][j]) return true;
        if(a[i][j]==a[i][k]+a[k][j]) m[P(i,j)]++;
      }
    }
  }

  return false;
}

int main(){
  cin>>n;
  rep(i,n){
    rep(j,n){
      cin>>a[i][j];
    }
  }

  if(search()){
    cout<<-1<<endl;
    return 0;
  }

  ll ans=0;
  rep(i,n){
    FOR(j,i+1,n){
      if(m[P(i,j)]) continue;
      ans+=a[i][j];
    }
  }

  cout<<ans<<endl;


}
