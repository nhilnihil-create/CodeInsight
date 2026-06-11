#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#define MOD 1000000007
#define mkp make_pair
typedef long long ll;
using namespace std;

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


int N,M;

int main(){
  cin>>N>>M;
  vector<int> L(N),R(N);
  for(int i=0;i<N;i++) cin>>L[i]>>R[i];

  vector<pair<int,int>> v;
  for(int i=0;i<N;i++){
      v.push_back(mkp(R[i]-L[i]+1,i));
  }

  sort(v.begin(),v.end());

  int cnt=0;
  vector<int> ans(M+1,0);
  for(int i=1;i<=M;i++){
      ans[i]=N-cnt;
      for(int j=1;i*j<=M;j++){
          ans[i]+=sum(i*j,i*j+1,0,0,M+1);
      }

      while(cnt<N){
          if(v[cnt].first==i){
              int now=v[cnt].second;
              add(L[now],R[now]+1,1,0,0,M+1);
              cnt++;
          }else break;
      }
  }

  for(int i=1;i<=M;i++) cout<<ans[i]<<endl;

  return 0;
}
