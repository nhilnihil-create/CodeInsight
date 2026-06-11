#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  int n,m;
  int a[200010],b[200010];
  cin>>n>>m;
  rep(i,m)cin>>a[i]>>b[i];

  int next[200010],last[200010];
  int size=0,size1=0;

  bool f1[200010],f2[200010];
  rep(i,n+1){
    f1[i]=false;
    f2[i]=false;
  }
  rep(i,n+1){
    if(a[i]==1)f1[b[i]]=true;
    if(b[i]==n)f2[a[i]]=true;
  }

  rep(i,n){
    if(f1[i]&&f2[i]){
      cout<<"POSSIBLE"<<endl;
      return 0;
    }
  }

  cout<<"IMPOSSIBLE"<<endl;
  return 0;
}
