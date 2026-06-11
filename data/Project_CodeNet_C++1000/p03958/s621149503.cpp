#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<int,int>

int main(){
  int k,t;
  cin>>k>>t;
  vector<int> a(t);
  rep(i,t){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  int m = a[t-1];
  rep(i,t-1){
    m-=a[i];
  }
  cout<<max(m-1,0)<<endl;
}
