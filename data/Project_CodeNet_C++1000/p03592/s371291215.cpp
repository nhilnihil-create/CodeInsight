#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;
  int k;
  cin >> k;
  rep(a,n+1)rep(b,m+1){
    int cnt = a*b + (n-a)*(m-b);
    if(cnt==k){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
    

}
