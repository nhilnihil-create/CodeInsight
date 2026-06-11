#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)

int main(){
  int n,m,k; 
  cin >> n >> m >>k;
  bool a=false;
  rep(i,n+1){
    rep(j,m+1){
    int x,y;
      x=i;
      y=j;
      if(m*x+n*y-2*x*y==k){
        a=true;
        break;
      }
    }
      if(a)break;
  }
  if(a) cout << "Yes" << endl;
  else cout << "No" << endl;
}