#include <bits/stdc++.h>
using namespace std;

template<typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}

signed main(){
  int N;cin>>N;
  vector<int> v(N);
  for(int i=0;i<N;i++)cin>>v[i];
  v.push_back(-1);
  sort(v.rbegin(),v.rend());
  int now=0;
  while(now+1<v[now+1])now++;
  int tmp=now;
  int a=v[now]-now-1;
  int b=0;
  while(v[now+1]>tmp)now++,b++;
  if(a&1)fin("First");
  if(b&1)fin("First");
  fin("Second");
}
