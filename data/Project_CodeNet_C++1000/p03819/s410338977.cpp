#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

vector<int> seg;
int N;

int kosu(int x){
  x+=N-1;
  int ans=seg[x];
  while(x>0){
    x=(x-1)/2;
    ans+=seg[x];
  }
  return ans;
}

void update(int a,int b, int k=0, int l=0, int r=-1){
  if(r<0) r=N;
  if(r<=a||b<=l) return;
  if(a<=l&&r<=b) {
    seg[k]++;
    return;
  }
  update(a,b,2*k+1,l,(l+r)/2);
  update(a,b,2*k+2,(l+r)/2,r);
  return;
}

struct t{
  int d;
  int num;
  bool operator<(const struct t &r) const{
    return d<r.d;
  }
};

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> kl(n,0),kr(n,0);
  vector<struct t> k(n);
  for(int i=0;i<n;i++){
    cin >> kl[i] >> kr[i];
    k[i]={kr[i]-kl[i]+1,i};
  }
  sort(k.begin(),k.end());
  // for(int i=0;i<n;i++) cout << k[i].d << endl;
  N=1;
  while(N<m+1) N*=2;
  seg=vector<int>(2*N-1,0);
  int now=0;
  int ans=0;
  for(int i=1;i<=m;i++){
    for(;now<n&&i>k[now].d;now++){
      update(kl[k[now].num],kr[k[now].num]+1);
    }
    ans=n-now;
    for(int j=0;j<=m;j+=i){
      ans+=kosu(j);
    }
    // for(int j=0;j<=m;j++){
    //   cout << kosu(j) <<" ";
    // }
    // cout << endl;
    cout << ans << endl;
  }
  return 0;
}
