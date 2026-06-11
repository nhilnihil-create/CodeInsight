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
  int n;
  cin>>n;
  vector<int> x(n),a(n*n,-1);
  for(int i=0;i<n;i++){
    cin>>x[i];
    x[i]--;
    a[x[i]]=i;
  }
  int cnt=0;
  for(int i=0;i<n*n;i++){
    if(a[i]==-1)continue;
    for(int j=0;j<a[i];j++){
	 while(a[cnt]!=-1){
	   cnt++;
	 }
	 if(cnt>i){
	   cout<<"No"<<endl;
	   return 0;
	 }
	 a[cnt]=a[i];
    }
  }
  cnt=n*n-1;
  vector<int> used(n,0);
  for(int i=n*n-1;i>=0;i--){
    if(a[i]==-1)continue;
    if(used[a[i]])continue;
    used[a[i]]=1;
    for(int j=0;j<n-a[i]-1;j++){
	 while(a[cnt]!=-1){
	   cnt--;
	 }
	 if(cnt<i){
	   cout<<"No"<<endl;
	   return 0;
	 }
	 a[cnt]=a[i];
    }
  }
  cout<<"Yes"<<endl;
  for(int i=0;i<n*n;i++){
    if(i)cout<<" ";
    cout<<a[i]+1;
  }
  cout<<endl;
  return 0;
}
