#include <bits/stdc++.h>
const int INF=1e9;
//const int MOD=1e9+7;
const int MOD=998244353;
const long long LINF=1e18;
using namespace std;
#define int long long
#define fin {cout<<"-1"<<endl;return 0;}
//template
//main
signed main(){
  int N;cin>>N;
  std::vector<int> v(N),ans(N,0);
  for(int i=0;i<N;i++)cin>>v[i];
  int ma=0;
  std::vector<int> w;
  for(int i=0;i<N;i++){
    if(v[i]>ma){
      ma=v[i];
      w.push_back(i);
    }
  }
  int K=w.size();
  int now=0;
  std::vector<int> sumv(K,0),sumn(K,0);
  //sumv[i]はans[w[i]]にのみ迷惑のかかる値の合計 (v[w[i-1]],v[w[i]]]が対象
  //sumn[i]はans[w[i]]にのみ迷惑のかかる場所の合計
  //cout<<w[0]<<endl;
  int nnow=K-1;
  for(int i=N-1;i>=0;i--){
    if(v[i]<=v[w[0]])continue;
    if(i==w[nnow]){
      sumn[nnow]++;
      sumv[nnow]+=v[w[nnow]]-v[w[nnow-1]];
      nnow--;
      continue;
    }
    int l=0,h=K;
    while(h-l>1){
      int m=(h+l)/2;
      if(v[i]>v[w[m]])l=m;
      else h=m;
    }
    //cout<<i<<" "<<l<<endl;
    sumv[h]+=v[i]-v[w[l]];
    sumn[h]++;
  }
  int num=0;
  //cout<<"-------"<<endl;
  //for(int i=0;i<K;i++)cout<<sumv[i]<<" "<<sumn[i]<<endl;
  //cout<<"-------"<<endl;
  for(int i=K-1;i>0;i--){
    ans[w[i]]=sumv[i];
    if(i!=K-1)ans[w[i]]+=num*(v[w[i]]-v[w[i-1]]);
    num+=sumn[i];
  }
  int sum=0;
  for(int i=0;i<N;i++)sum+=v[i];
  for(int i=0;i<N;i++)sum-=ans[i];
  ans[w[0]]=sum;
  for(int p:ans)cout<<p<<endl;
}
