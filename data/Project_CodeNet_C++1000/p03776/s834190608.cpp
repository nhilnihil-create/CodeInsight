#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll c[55][55];
ll com(int n,int k){
  if(c[n][k]>0){
    return c[n][k];
  }
  if(n<k||n<0||k<0){
    return 0;
  }
  if(k==0||k==n){
    return 1;
  }
  return c[n][k]=com(n-1,k-1)+com(n-1,k);
}
int main(){
  ld n,a,b;
  cin >> n >> a >> b;
  vector<ld> v(n);
  map<ld,ll> mp1;
  map<ld,ll> mp2;
  for(int i=0;i<n;i++){
    cin >> v[i];
    mp1[v[i]]++;
  }
  sort(v.begin(),v.end(),greater<ld>());
  ld ans=0;
  for(int i=0;i<a;i++){
    ans+=v[i];
    mp2[v[i]]++;
  }
  cout << fixed << setprecision(15) << ans/a << endl;
  ll res;
  if(v[0]!=v[a-1]){
    res=com(mp1[v[a-1]],mp2[v[a-1]]);
  }
  else{
    res=0;
    int t=min(mp1[v[a-1]],(ll)b);
    for(int i=a-1;i<t;i++){
      if(i!=a-1){
        mp2[v[a-1]]++;
      }
      res+=com(mp1[v[a-1]],mp2[v[a-1]]);
    }
  }
  cout << res << endl;
}