#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main() {
    int n;
    cin>>n;
    ll a[n],b[n];
    rep(i,n){
      cin>>a[i]>>b[i];
    }
    ll count=0;
    for (int i = n-1; i >=0; i--)
    {
      ll N=count+a[i];
      if(b[i]==1) continue;
      if(N==0){
        continue;
      }
      if(N<=b[i]){
        count+=b[i]-N;
      }else
      {if(N%b[i]==0) continue;
        count+=b[i]-(N%b[i]);
      }
     // cout<<count<<endl;
    }
    cout<<count<<endl;
    return 0;
}
