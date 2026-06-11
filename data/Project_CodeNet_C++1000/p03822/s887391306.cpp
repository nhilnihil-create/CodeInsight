#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=1000000007;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
vector<vector<int>>graph;
int dfs(int now,int cnt){
  if(graph[now].size()==0)return cnt;
  vector<int> tmp;
  for(int v:graph[now]){
     int t=dfs(v,cnt+1);
      tmp.push_back(t);
  }
  int res=0;
  sort(all(tmp),greater<int>());
  int cn=0;
  for(int u:tmp){
      chmax(res,u+cn);
      cn++;
  }
   return res;
}
int main(){
    int n;
    cin>>n;
    graph.resize(n);
    for(int i=1;i<n;i++){
        int a;
        cin>>a;
        graph[a-1].push_back(i);
    }
    cout<<dfs(0,0)<<endl;
}

