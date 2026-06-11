#include<bits/stdc++.h>

using namespace std;
#define INF (1<<28)
#define DEKAI 1000000007
#define lp(i,n) for(int i=0;i<n;i++)
#define int long long
signed main(){
  int n;
  cin>>n;
  cout<<50<<endl;
  int a[50];
  int c=n/50;
  lp(i,50) a[i]=i+c;
  lp(i,n%50){
    lp(j,50){
      if(i==j) a[j]+=50;
      else a[j]--;
    }
  }
  lp(i,50) cout<<a[i]<<" ";
  cout<<endl;
  return 0;
}