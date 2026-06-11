#include "bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define all(a) a.begin(),a.end()
typedef pair<int,int> P;
const long long mod=1000000007;
const long long inf=1ll<<61;
int a[100006];
signed main(){
  int n;cin>>n;
  rep(i,n)cin>>a[i];
  sort(a,a+n);
  int lb=-1,ub=n;
  while(ub-lb>1){
    int mi=(ub+lb)/2;
    int fi=0;
    rep(i,mi+1)fi+=a[i];
    int flg=0;
    for(int i=mi+1;i<n;i++){
      if(fi*2<a[i])flg++;
      else{
        fi+=a[i];
      }
    }
    if(flg)lb=mi;
    else ub=mi;
  }
  cout<<n-ub<<endl;
}