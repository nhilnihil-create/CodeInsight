#include<iostream>
#include<vector>

using namespace std;

int d[100001][2],visit[100001]={};
vector<vector<int>> v(100001);

int dfs(int p,int a){
  visit[p]=1;
  for(int i=0;i<v[p].size();i++)
    if(visit[v[p][i]]==0){
      d[v[p][i]][a]=d[p][a]+1;
      dfs(v[p][i],a);
    }
}

int main(){
  int n,a,b,cnt=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin >> a >>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  dfs(1,0);
  d[1][0]=0;
  for(int i=1;i<=n;i++)
    visit[i]=0;
  d[n][1]=0;
  dfs(n,1);
  for(int i=1;i<=n;i++){
    if(d[i][0]>d[i][1])
      cnt++;
    else
      cnt--;
  }
  if(cnt>=0)
    cout << "Snuke" <<endl;
  else
    cout << "Fennec" <<endl;
}