#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  const int INF=1e9;
  std::vector<queue<int>> que(N),que1(N),que2(N);
  int a,b;
  for(int i=0;i<N-1;i++){
    cin>>a>>b;
    a--;b--;
    que[a].push(b);
    que[b].push(a);
    que1[a].push(b);
    que1[b].push(a);
    que2[a].push(b);
    que2[b].push(a);
  }
  std::vector<int> da(N,INF),db(N,INF);
  da[0]=0;
  db[N-1]=0;
  queue<int> d;
  d.push(0);
  while(d.size()){
    int k=d.front();
    d.pop();
    while(que1[k].size()){
      int c=que1[k].front();
      que1[k].pop();
      if(da[c]==INF){
        da[c]=da[k]+1;
        d.push(c);
      }
    }
  }
  d.push(N-1);
  while(d.size()){
    int k=d.front();
    d.pop();
    while(que2[k].size()){
      int c=que2[k].front();
      que2[k].pop();
      if(db[c]==INF){
        db[c]=db[k]+1;
        d.push(c);
      }
    }
  }
  int m=INF;
  int mm=INF;
  int j;
  for(int i=0;i<N;i++){
    if(m>abs(da[i]-db[i])){
      m=abs(da[i]-db[i]);
      mm=da[i];
      j=i;
    }
  }
  for(int i=0;i<N;i++){
    if(m==abs(da[i]-db[i])&&mm>da[i]){
      mm=da[i];
      j=i;
    }
  }
  if(da[j]-db[j]<=0){
    int k=N-1;
    int ans=0;
    queue<int> ll;
    ll.push(k);
    std::vector<int> pp(N,INF);
    pp[j]=0;
    while(ll.size()){
      int tt=ll.front();
      ll.pop();
      if(pp[tt]){
        pp[tt]=0;
        ans++;
        while(que[tt].size()){
          int ii=que[tt].front();
          que[tt].pop();
          ll.push(ii);
        }
      }
    }
    if(ans>=(N+1)/2)cout<<"Snuke"<<endl;
    else cout<<"Fennec"<<endl;
    //cout<<333<<ans<<endl;
  }
  else{
    int k=0;
    int ans=0;
    queue<int> ll;
    ll.push(k);
    std::vector<int> pp(N,INF);
    pp[j]=0;
    while(ll.size()){
      int tt=ll.front();
      ll.pop();
      if(pp[tt]){
        pp[tt]=0;
        ans++;
        while(que[tt].size()){
          int ii=que[tt].front();
          que[tt].pop();
          ll.push(ii);
        }
      }
    }
    if(ans>=N/2+1)cout<<"Fennec"<<endl;
    else cout<<"Snuke"<<endl;
    //cout<<555<<ans<<endl;
  }
}
