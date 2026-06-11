#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

const int DAT_SIZE=(1<<18)-1;

ll datA[DAT_SIZE], datB[DAT_SIZE];

// [a,b)にxを加算する
// add(a,b,x,0,0,N);
void add(int a, int b, int x, int k, int l, int r){
  if(a<=l && r<=b) datA[k]+=x;
  else if(l<b && a<r){
    datB[k]+=(min(b,r)-max(a,l))*x;
    add(a,b,x,k*2+1,l,(l+r)/2);
    add(a,b,x,k*2+2,(l+r)/2,r);
  }
}

// [a,b)の和を計算する
// sum(a,b,0,0,N)
ll sum(int a, int b, int k, int l, int r){
  if(b<=l || r<=a) return 0;
  else if(a<=l && r<=b) return (datA[k]*(r-l)+datB[k]);
  else{
    ll res=(min(b,r)-max(a,l))*datA[k];
    res+=sum(a,b,k*2+1,l,(l+r)/2);
    res+=sum(a,b,k*2+2,(l+r)/2,r);
    return res;
  }
}

int main(){
  int N,M; cin>>N>>M;
  vector<tuple<int,int,int> > V(N);
  rep(i,N){
    int l,r; cin>>l>>r;
    V[i]=make_tuple(r-l+1,l,r);
  }
  sort(V.begin(),V.end());
  cout<<N<<endl;
  int dekai=N,ind=0;
  for(int d=2;d<=M;d++){
    while(ind<N){
      if(get<0>(V[ind])>=d) break;
      int l=get<1>(V[ind]),r=get<2>(V[ind]);
      ind++,dekai--;
      add(l,r+1,1,0,0,M+1);
    }
    ll tmp=dekai;
    for(int i=d;i<=M;i+=d){
      tmp+=sum(i,i+1,0,0,M+1);
    }
    cout<<tmp<<endl;
  }
  return 0;
}
