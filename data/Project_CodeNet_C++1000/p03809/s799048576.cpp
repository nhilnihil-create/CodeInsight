#include<bits/stdc++.h>
#define N 100005
using namespace std;

typedef long long ll;

int n, A[N], ans=1;
vector<int> G[N];

ll dfs(int x, int px){
  
  vector<ll> v;
  
  for(int i=0;i<G[x].size();i++)
    if(G[x][i]!=px) v.push_back(dfs(G[x][i], x));
  
  if(v.empty()) return A[x];
  
  ll res=0;
  
  for(int i=0;i<v.size();i++) res+=v[i];
  
  sort(v.begin(),v.end());
  
  ll q=res-A[x], sum=0;
  
  if(v[v.size()-1]*2<=res) sum=res/2;
  else sum=(res-v[v.size()-1]);
  //if(x==1) cout<<q<<' '<<sum<<' '<<v[1]<<' '<<res<<endl;
  if(q<0) ans=0;
  
  if(q>sum) ans=0;
  else res-=q*2;
  
  if(px==-1&&A[x]!=res) ans=0;
  
  return res;
}

int main(){
  
  cin>>n;
  
  for(int i=0;i<n;i++) scanf("%d", &A[i]);
  
  int a, b;
  
  for(int i=0;i<n-1;i++){
    scanf("%d %d", &a, &b);
    G[a-1].push_back(b-1);
    G[b-1].push_back(a-1);
  }
  
  int root;
  
  for(int i=0;i<n;i++)
    if(G[i].size()==1){
      root=i;
      break;
    }
  
  dfs(root, -1);
  
  if(ans) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  
  return 0;
}
