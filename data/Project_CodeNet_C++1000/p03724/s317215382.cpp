#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n,m;
  cin >> n >> m;
  int k[n];
  rep(i,n)k[i]=0;
  rep(i,2*m){
    int o;
    cin >> o;
    o--;
    k[o]++;
  }
  int ans=0;
  rep(i,n)ans+=k[i]%2;
  if(ans==0)cout << "YES" << endl;
  else cout << "NO" << endl;
}
