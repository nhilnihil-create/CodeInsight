#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  int t[n];
  rep(i,0,n) cin>>t[i];
  int sum=0;
  rep(i,0,n) sum+=t[i];
  int m;
  cin>>m;
  rep(i,0,m){
    int p,x;
    cin>>p>>x;
    cout<<sum-t[p-1]+x<<endl;
  }
}