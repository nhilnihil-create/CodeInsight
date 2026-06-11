#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  int sum=0;
  rep(i,n){
    cin >> a.at(i);
    sum+=a.at(i);
  }
  ll ans=0,as=0,p=sum/n,q=(sum+n-1)/n;
  rep(i,n){
    ans+=(p-a.at(i))*(p-a.at(i));
    as+=(q-a.at(i))*(q-a.at(i));
  }
  cout << min(as,ans);

}
      
  