#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int N,M;
int L[300030],R[300030];
vector<pair<ll,int>> v;

const int DAT_SIZE=(1<<18)-1;

ll data[DAT_SIZE],datb[DAT_SIZE];

void add(int a,int b,int x,int k,int l,int r){
  if(a<=l&&r<=b){
    data[k]+=x;
  }
  else if(l<b&&a<r){
    datb[k]+=(min(b,r)-max(a,l))*x;
    add(a,b,x,k*2+1,l,(l+r)/2);
    add(a,b,x,k*2+2,(l+r)/2,r);
  }
}

//[a,b),[l,r)
ll sum(int a,int b,int k,int l,int r){
  if(b<=l||r<=a){
    return 0;
  }
  else if(a<=l&&r<=b){
    return data[k]*(r-l)+datb[k];
  }
  else{
    ll res=(min(b,r)-max(a,l))*data[k];
    res+=sum(a,b,k*2+1,l,(l+r)/2);
    res+=sum(a,b,k*2+2,(l+r)/2,r);
    return res;
  }
}


int main(){
  cin>>N>>M;
  for(int i=0;i<N;i++){
      cin>>L[i]>>R[i];
      v.push_back(make_pair(R[i]-L[i],i));
  }
  sort(v.begin(),v.end());

  vector<int> ans;
  ans.push_back(N);
  int now=0;
  for(int i=0;i<v.size();i++){
      if(v[i].first==0){
          int u=v[i].second;
          add(L[u],R[u]+1,1,0,0,M+1);
          now++;
      }else break;
  }
  for(int i=2;i<=M;i++){
      int res=N-now;
      for(int j=i;j<=M;j+=i){
          res+=sum(j,j+1,0,0,M+1);
      }
      for(int j=now;j<v.size();j++){
          if(v[j].first==i-1){
              int u=v[j].second;
              add(L[u],R[u]+1,1,0,0,M+1);
              now++;
          }else break;
      }
      ans.push_back(res);
  }

  for(int i=0;i<M;i++){
      cout<<ans[i]<<endl;
  }

  return 0;
}
