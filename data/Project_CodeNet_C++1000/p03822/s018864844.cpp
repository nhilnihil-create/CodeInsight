#include <bits/stdc++.h>
const int INF=1e9,MOD=1e9+7;
const long long LINF=1e18;
using namespace std;
#define int long long
//template
//main
signed main(){

  int N;cin>>N;
  std::vector<int> v(N);
  for(int i=1;i<N;i++){cin>>v[i];v[i]--;}

  std::vector<int> w(N,0);
  for(int i=1;i<N;i++)w[v[i]]++;
  queue<int> que;
  for(int i=0;i<N;i++)if(w[i]==0)que.push(i);
  std::vector<int> r(N,0);
  std::vector<int> s[N];
  while(que.size()){
    int p=que.front();que.pop();
    s[v[p]].push_back(r[p]);
    if(s[v[p]].size()==w[v[p]]){
      int res=0,c=1;
      sort(s[v[p]].rbegin(),s[v[p]].rend());
      for(int a:s[v[p]])res=max(res,a+c++);
      r[v[p]]=res;
      if(v[p])que.push(v[p]);
    }
  }
  cout<<r[0]<<endl;
}
