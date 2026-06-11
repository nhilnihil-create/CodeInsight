#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000
//配列を順に確認していき、最大値を返す関数

signed main() {
  int n,k;cin>>n>>k;
  vector<int>a(n);
  vector<int>b(n);
  int ans=INF;
  rep(i,n){cin>>a[i];}
  //bit全探索でN個からK個選んでいるならば、
  for(int bit=0;bit<(1<<n);bit++){
    int count=0;
    vector<int>c(n);
    for(int i=0;i<n;i++){
      if(bit&(1<<i)){
        count++;
        c[i]=1;
      }
    }
      if(count==k){
          //前から順に確認していって、それまでの最大値saidai（i）＋１にするのに必要なコストを、tempにたす
          int saidai=0;
          int tmpcst=0;
          rep(j,n){
            b[j]=a[j];
            if(c[j]){
              if(saidai>=a[j]){b[j]=saidai+1;}
              tmpcst+=(b[j]-a[j]);
            }
            saidai=max(saidai,b[j]);
          }
          ans=min(tmpcst,ans);
      }
    }


  cout<<ans<<endl;
}
