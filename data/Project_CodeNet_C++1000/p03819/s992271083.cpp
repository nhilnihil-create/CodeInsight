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

const int DAT_SIZE=(1<<18)-1;

ll data[DAT_SIZE];
ll datb[DAT_SIZE];

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
  int n,m;
  cin>>n>>m;
  vector<pair<int,pair<int,int>>> v;
  for(int i=0;i<n;i++){
    int l,r;
    cin>>l>>r;
    v.push_back(make_pair(r-l,make_pair(l,r)));
  }
  sort(v.begin(),v.end());

  int mit=0;
  for(int q=1;q<=m;q++){
    int z=lower_bound(v.begin(),v.end(),make_pair(q,make_pair(0,0)))-v.begin();
    int ans=n-z;
    int nextmit=z;
    for(int i=mit;i<nextmit;i++){
      pair<int,int> u=v[i].second;
      add(u.first,u.second+1,1,0,0,m+1);
    }

    mit=nextmit;
    for(int i=q;i<=m;i+=q){
      ans+=sum(i,i+1,0,0,m+1);
    }
    cout<<ans<<endl;
  }

  return 0;
}
