#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin>>N>>K;
  vector<long> a(N);
  for(int i=0;i<N;i++) cin>>a[i];
  if(N==1){
    if(a[0]==K) cout<<"POSSIBLE"<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
    return 0;
  }
  sort(a.begin(),a.end());
  if(a[N-1]<K){
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
  }
  long g=gcd(a[0],a[1]);
  for(int i=0;i<N;i++) g=gcd(g,a[i]);

  for(int i=0;i<N;i++){
    if(a[i]<K) continue;
    else if(a[i]==K){
      cout<<"POSSIBLE"<<endl;
      return 0;
    }
    else{
      if(a[i]%g==K%g){
        cout<<"POSSIBLE"<<endl;
        return 0;
      }
    }
  }

  cout<<"IMPOSSIBLE"<<endl;

  }
