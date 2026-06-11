#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef long long ll;
const int inf   = 1<<30;
const int mod=1000000007;

int edge[100001];
bool used[100001];
ll cnt;
vector<int> v;
void dfs (int i){
  used[i]=true;
  v.push_back(i);
  cnt++;
  if(!used[edge[i]])dfs(edge[i]);
  }
    
  
int main(){
  int n;cin>>n;
  ll x[n];
  rep(i,n)cin>>x[i];
  rep(i,n-1)edge[i]=i;
  int m;
  ll k;
  cin>>m>>k;
  int a[m];
  rep(i,m){
    cin>>a[i];
    swap(edge[a[i]-2],edge[a[i]-1]);
    }
  rep(i,n-1)used[i]=false;
  int dist[n-1];
  rep(i,n-1){
    if(!used[i]){
      v.clear();
      cnt=0;
      dfs(i);
      ll r=k%cnt;
      rep(j,cnt){
        int fin=(j+r)%cnt;
        dist[v[j]]=x[v[fin]+1]-x[v[fin]];
        }
      }
    }
  ll ans=x[0];
  cout<<x[0]<<endl;
  rep(i,n-1){
    ans+=dist[i];
    cout<<ans<<endl;
    }
  return 0;
  }