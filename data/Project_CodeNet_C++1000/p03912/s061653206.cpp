#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;cin >> n >> m;
  vector<int> c(m),t(100005);
  map<int,int> mp;
  for(int i=0;i<n;i++){
    int x;cin >> x;
    c[x%m]++;
    mp[x]++;
  }
  for(int i=1;i<=100000;i++){
    t[i]=mp[i]/2;
  }
  int ans=0;
  for(int i=0;i<=m/2;i++){
    if(i==0){
      ans+=c[0]/2;
      c[0]=1;
    }
    else if(i==m/2&&m%2==0){
      ans+=c[m/2]/2;
      c[m/2]=1;
    }
    else{
      int k=min(c[i],c[m-i]);
      ans+=k;
      c[i]-=k;
      c[m-i]-=k;
    }
  }
  for(int i=1;i<=100000;i++){
    if(c[i%m]/2>=t[i]){
      ans+=t[i];
      c[i%m]-=t[i]*2;
    }
    else{
      ans+=c[i%m]/2;
      c[i%m]=0;
    }
  }
  cout << ans << endl;
}