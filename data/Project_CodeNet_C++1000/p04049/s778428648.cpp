#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;

vector<int> g[2222];

void dfs(int cnt[],int used[],int n,int k){
  if(used[n])return;
  cnt[n]=1;
  used[n]=1;
  if(k==0)return;
  for(int i=0;i<g[n].size();i++){
    dfs(cnt,used,g[n][i],k-1);
  }
}

int main(){
  int n,k;
  cin>>n>>k;
  int a[2222],b[2222];
  for(int i=0;i<n-1;i++){
    cin>>a[i]>>b[i];
    a[i]--,b[i]--;
    g[a[i]].pb(b[i]);
    g[b[i]].pb(a[i]);
  }

  int ma=0;
  
  if(k%2){
    for(int i=0;i<n-1;i++){
	 int cnt[2222]={};
	 int used[2222]={};
	 dfs(cnt,used,a[i],k/2);
	 fill_n(used,2222,0);
	 dfs(cnt,used,b[i],k/2);
	 int sum=0;
	 for(int j=0;j<n;j++){
	   sum+=cnt[j];
	 }
	 ma=max(ma,sum);
    }
  }else{
    for(int i=0;i<n;i++){
	 int cnt[2222]={};
	 int used[2222]={};
	 dfs(cnt,used,i,k/2);
	 int sum=0;
	 for(int j=0;j<n;j++){
	   sum+=cnt[j];
	 }
	 ma=max(ma,sum);
    }
  }

  cout<<n-ma<<endl;
  
  return 0;
}
