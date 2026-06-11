#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >>n;
  int a[n];
  int k=1;
  multiset<int> s;
  rep(i,n){
    cin >> a[i];
    s.insert(a[i]);
    k=max(k,a[i]);
  }
  sort(a,a+n);
  bool ok=true;
  if(k%2==0){
    rep(i,n){
      if(a[i]==k/2){
	if(s.count(a[i])!=1) ok=false;	
      }
      else if(a[i]<=k && a[i]>=k/2+1){
	if(s.count(a[i])<2) ok = false;
      }
      else ok=false;
    }
    for(int i=k/2+1;i<=k;i++){
      if(s.count(i)<2) ok=false;
    }
    if(s.count(k/2)!=1) ok=false;
  }
  else{
    rep(i,n){
      if(a[i]==(k+1)/2){
	if(s.count(a[i])!=2) ok=false;
      }
      else if(a[i]<=k && a[i]>=(k+1)/2+1){
	if(s.count(a[i]<2)) ok=false;
      }
      else ok=false;
    }
    for(int i=(k+1)/2+1;i<=k;i++){
      if(s.count(i)<2) ok=false;
    }
    if(s.count((k+1)/2)!=2) ok=false;
  }
  if(k+1>n) ok=false;
  if(ok) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
  
  


  
  return 0;
    

}
