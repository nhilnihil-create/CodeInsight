#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<int> hate(10);

bool suki(int n){
  bool ok=1;
  while(n>0){
    if(hate[n%10]==1)ok=0;
    n/=10;
  }
  return ok;
}

int main(){
  int n,k;
  cin>>n>>k;
  rep(i,10){
    hate[i]=0;
  }
  rep(i,k){
    int l; cin>>l;
    hate[l]=1;
  }
  int ans;
  while(true){
    int tmp=n;
    bool ok;
    ok=suki(tmp);
    if(ok){
      ans=n; 
      break;
    }
    n++;
  }
  cout<<ans<<endl;
}

