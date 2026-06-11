#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll stone[100005]={0};
int in[100005]={0};
int idx[100005]={0},nidx[100005]={0};
vector<int> kn[100005],node[100005];
ll dp[100005]={0};
int main(){
  int n;
  cin>>n;
  for(int i=1;i<=n;i++) cin>>stone[i];
  vector<P> vec;
  for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    vec.push_back(P(a,b));
    in[a]++;
    in[b]++;
    kn[a].push_back(b);
    kn[b].push_back(a);
  }
  if(n==2){
    if(stone[1]==stone[2]) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
  }
  int ma=0,mp=0;
  for(int i=1;i<=n;i++){
    if(ma<in[i]){
      ma=in[i];
      mp=i;
    }
  }
  queue<int> que;
  vector<bool> used(n+1,false);
  int cnt=0;
  que.push(mp);
  while(!que.empty()){
    int pos=que.front();
    que.pop();
    used[pos]=true;
    idx[cnt]=pos;
    nidx[pos]=cnt;
    cnt++;
    for(int i=0;i<kn[pos].size();i++){
      int to=kn[pos][i];
      if(!used[to]) {
        que.push(to);
        node[pos].push_back(to);
      }
    }
  }
  /*cout<<mp<<endl;
  for(int i=0;i<n;i++) cout<<idx[i]<<" ";
  cout<<endl;*/
  for(int i=n-1;i>=0;i--){
    int pos=idx[i];
    if(node[pos].size()==0) {
      dp[pos]=stone[pos];
      continue;
    }
    ll a=0,a1=20000000000,a2=0;
    for(int j=0;j<node[pos].size();j++){
      int son=node[pos][j];
      a+=dp[son];
      a1=min(a1,dp[son]);
      a2=max(a2,dp[son]);
    }
    ll c=stone[pos];
    ll p=a-c;
    if(p<0||a-a2-p<0||p*2>a){
      cout<<"NO"<<endl;
      return 0;
    }
    else dp[pos]=2*c-a;
  }
  /*for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
  cout<<endl;*/
  if(dp[mp]==0) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
