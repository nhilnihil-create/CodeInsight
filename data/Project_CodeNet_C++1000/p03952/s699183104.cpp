#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF INT_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N,x;
  cin>>N>>x;
  if(N==2){
    if(x==2){
      cout<<"Yes"<<endl;
      cout<<1<<endl;
      cout<<2<<endl;
      cout<<3<<endl;
    }
    else cout<<"No"<<endl;
    return 0;
  }
  if(1<x&&x<2*N-1){
    cout<<"Yes"<<endl;
    vector<int>ans(2*N-1,0);
    ans[N-3]=x-1;
    ans[N-2]=x;
    ans[N-1]=x+1;
    ans[N]=x-2;
    if(x==2){
      ans[N-3]=x+1;
      ans[N-2]=x;
      ans[N-1]=x-1;
      ans[N]=x+2;
    }
    int j=0;
    for(int i=1;i<=2*N-1;i++){
      if(x==2){
        if(x-1<=i&&i<=x+2)continue;
      }
      else{
        if(x-2<=i&&i<=x+1)continue;
      }

      while(ans[j]!=0)j++;
      ans[j]=i;
    }
    for(auto it:ans)cout<<it<<endl;
  }
  else cout<<"No"<<endl;
  return 0;
}
