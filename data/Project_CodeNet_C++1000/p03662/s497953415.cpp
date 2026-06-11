#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define NMAX 100000
#define P pair<int,int>
int main(){
  int n;
  cin >> n;
  int a,b;
  vector<int> v[NMAX+1];
  queue<P> q;
  bool used[NMAX+1]={};
  for(int i=0;i<n-1;i++){
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  q.push(P(1,1));
  q.push(P(n,0));
  int fcnt=0, scnt=0;
  while(!q.empty()){
    P tp = q.front();
    q.pop();
    if(used[tp.first]) continue;
    if(tp.second==1) fcnt++;
    else scnt++;
    used[tp.first] = true;
    for(int i=0;i<v[tp.first].size();i++){
      if(!used[v[tp.first][i]])
        q.push(P(v[tp.first][i], tp.second));
    }
  }
  if(fcnt > scnt) cout << "Fennec" << endl;
  else cout << "Snuke" << endl;
}