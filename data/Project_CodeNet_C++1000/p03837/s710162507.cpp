#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;
#define rep(i,m,n) for(int i=m;i<n;i++)

int main(){
  int n,m;
  cin>>n>>m;
  vector<P> edge[n];
  rep(i,0,m){
    int a,b,c;
    cin>>a>>b>>c;
    edge[a-1].push_back(P(b-1,c));
    edge[b-1].push_back(P(a-1,c));
  }
  set<P> st;
  rep(i,0,n){
    int d[n];
    rep(j,0,n) d[j]=1e5;
    d[i]=0;
    priority_queue<P,vector<P>,greater<P>> q;
    q.push(P(0,i));
    int prev[n];
    rep(j,0,n) prev[j]=-1;
    while(q.size()){
      P p=q.top();
      q.pop();
      int v=p.second;
      if(d[v]<p.first) continue;
      for(P s:edge[v]){
        if(d[s.first]>d[v]+s.second){
          d[s.first]=d[v]+s.second;
          q.push(P(d[s.first],s.first));
          prev[s.first]=v;
        }
      }
    }
    rep(j,0,n){
      if(j==i) continue;
      int t=j;
      for(;t!=i;t=prev[t]){
        st.insert(P(t,prev[t]));
        st.insert(P(prev[t],t));
      }
    }
  }
  cout<<m-st.size()/2<<endl;
}