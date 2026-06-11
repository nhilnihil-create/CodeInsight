#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n;
  cin>>n;
  map<int,int> a;
  rep(i,n){
    int A; cin>>A;
    a[A]++;
  }
  int ans=-1;
  rep(x,100010){
    int now_ans=0;
    now_ans=a[x-1]+a[x]+a[x+1];
    ans=max(ans,now_ans);
  }
  cout<<ans<<endl;
}
