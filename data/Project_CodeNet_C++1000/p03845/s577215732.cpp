#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n,m,nodnk=0;
  cin>>n;
  vector<int> t(n);
  rep(i,n){
    cin>>t[i];
    nodnk+=t[i];
  }
  cin>>m;
  rep(i,m){
    int p,x;
    cin>>p>>x;
    p--;
    cout<<x-t[p]+nodnk<<endl;
  }
}