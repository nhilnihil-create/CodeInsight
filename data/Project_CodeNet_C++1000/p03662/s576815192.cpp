 #include<bits/stdc++.h>
using namespace std;
int main(){
  //int inf=1000000000;
  int n;cin>>n;
  int a[n-1],b[n-1];
  bool used[n+1];
  for(int i=0;i<=n;i++)used[i]=false;
  vector<int>list[n+1];
  for(int i=0;i<n-1;i++){
    cin>>a[i]>>b[i];
    list[a[i]].push_back(b[i]);
    list[b[i]].push_back(a[i]);
  }
  //cout<<list[4][0]<<list[4][1];return 0;
  int d[n+1];
  d[1]=0;
  used[1]=true;
  queue<int>q,dis;
  q.push(1);dis.push(0);
  for(;;){
    int x=q.front();int di=dis.front();
   // cout<<x<<endl;
    q.pop();dis.pop();
    if(x==n)break;
    for(int i=0;i<list[x].size();i++){
      int y=list[x][i];
      if(!used[y]){
      d[y]=di+1;
      q.push(y);dis.push(di+1);
        used[y]=true;
      }
    }
  }
  
  vector<int>str;
  str.push_back(n);
  int t=d[n];
  //cout<<t;return 0;
  int now=n;
  for(;;){
    for(int i=0;i<list[now].size();i++){
      if(d[list[now][i]]==t-1){
        str.push_back(list[now][i]);
        now=list[now][i];
        t--;
        break;
      }
    }
    if(t==0)break;
  }
  //cout<<3<<endl;return 0;
  int w=str.size()/2-1;
  for(int i=0;i<=n;i++)used[i]=false;
  queue<int>qn;
  qn.push(str[w]);
  int sum=1;
  used[str[w]]=true;
  int out=str[w+1];
  for(;;){
    int r=qn.front();
    qn.pop();
    
    for(int i=0;i<list[r].size();i++){
      int u=list[r][i];
      if(u!=out){
        if(used[u]==false){
          sum++;
          qn.push(u);
          used[u]=true;
          
        }
      }
    }
    if(qn.size()==0)break;
  }
  int summ=n-sum;
  if(sum<summ)cout<<"Fennec"<<endl;
  else cout<<"Snuke"<<endl;
}
    

