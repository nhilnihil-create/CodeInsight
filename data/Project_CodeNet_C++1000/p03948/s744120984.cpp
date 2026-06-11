#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>
#include <string>
#define pb push_back
#define mod 1000000007
#define all(x) x.begin(),x.end()
#define inf (int)(1e9)
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;

int max_a[111111];
int min_a[111111];
//bool use[111111];
map<int,int> mp;
int main(void){
  int n,t;
  cin>>n>>t;
  int x;
  vector<int> a;
  for(int i=0;i<n;i++){
    cin>>x;
    a.pb(x);
  }
  min_a[0]=a[0];
  max_a[n-1]=a[n-1];
  for(int i=1;i<n;i++){
    min_a[i]=min(min_a[i-1],a[i]);
    max_a[n-i-1]=max(max_a[n-i],a[n-i-1]);
  }
  int r=0;
  for(int i=0;i<n;i++){
    r=max(r,max_a[i]-min_a[i]);
  }
  int res=0;
  for(int i=0;i<n;i++){
    if(max_a[i]-min_a[i]==r){
      if(mp[max_a[i]]!=1) res++;
      mp[max_a[i]]=1;
    }
  }
  cout<<res<<endl;
  return 0;
}
