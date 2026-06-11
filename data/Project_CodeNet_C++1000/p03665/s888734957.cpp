#include<bits/stdc++.h>
using namespace std;

long long solve(long long n,long long r,long long e){
  long long ans=1;
  for(int i=0;i<r;i++){
    ans*=n-i;
    ans/=i+1;
  }
  for(int i=0;i<e;i++)
    ans*=2;
  return ans;
}

int main(){
  int n,p;
  cin >> n >> p;
  vector<int>a(n);
  for(int i=0;i<n;i++)
    cin >> a.at(i);
  long long o=0,e=0,ans=0;
  for(int i=0;i<n;i++)
    if(a.at(i)%2==0)
      e++;
  o=n-e;
  for(int i=(p==0?0:1);i<=o;i+=2){
    ans+=solve(o,i,e);
  }
  cout << ans << endl;
  //cout << n << "/" << e << endl;
  return 0;
}