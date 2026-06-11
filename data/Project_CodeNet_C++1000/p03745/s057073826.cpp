#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;

int main(){
  int n; cin >> n;
  ll a[n];
  rep(i,n) cin >> a[i];

  int ans =0;

  int check = 2;

  for(int i=0;i<n-1;i++){
    if(a[i]==a[i+1]) continue;
    bool pos;
    a[i+1]-a[i]>0 ? pos=true : pos = false;
    if(pos){
      if(check==2){
        check=0;
      }else if(check==1){
        ans++;
        check=2;
      }
    }else{
      if(check==2){
        check=1;
      }else if(check==0){
        ans++;
        check=2;
      }
    }
  }

  cout << ans+1 << endl;
}
