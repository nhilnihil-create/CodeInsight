#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;

int main(){
  int n,m,a[333][333];
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
	 cin>>a[i][j];
	 a[i][j]--;
    }
  }

  int ans=n;
  int cnt=0;
  int used[333]={};
  
  for(int i=0;i<m;i++){
    if(cnt==m)break;
    
    int sum[333]={};
    for(int j=0;j<n;j++){
	 for(int k=0;k<m;k++){
	   if(used[a[j][k]])continue;
	   sum[a[j][k]]++;
	   break;
	 }
    }

    int ma=0;
    for(int j=0;j<m;j++){
	 ma=max(ma,sum[j]);
    }
    ans=min(ma,ans);

    for(int j=0;j<m;j++){
	 if(sum[j]<ma)continue;
	 used[j]=1;
	 cnt++;
    }
  }

  cout<<ans<<endl;
  
  return 0;
}
