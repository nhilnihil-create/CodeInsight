#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin >> n >> k;
  vector<long>a(n);
  int i,j;
  for(i=0;i<n;i++){
    cin >> a[i];
  }
  sort(a.begin(),a.end(),greater<long>());
  vector<set<long> >num(n);
  int tmp = 0;
  vector<bool>chk(n,false);
  for(i=0;i<n;i++){
    num[i].insert(a[i]);
    if(a[i]>=k){
      tmp++;
      chk[i] = true;
    }
  }
  long tmppp = 0;
  for(i=tmp;i<n;i++){
    tmppp+=a[i];
  }
  if(tmppp<k)tmp = 99999999;
  long tmppp2 = tmppp;
  for(i=n-1;i>=tmp;i--){
    if(tmppp-a[i]<k)chk[i]=true;
    if(tmppp2-a[i]<k)chk[i]=true;
    else tmppp2-=a[i];
  }
  for(i=tmp;i<n;i++){
    for(j=tmp;j<n;j++){
      if(i != j && !chk[j]){
        set<long>tmpp;
        for(auto kk: num[j]){
          if(kk+a[i]>=k && kk+a[i]-a[j]<k)chk[j]=true;
          else if(kk+a[i]<k)tmpp.insert(kk+a[i]);
        }
        for(auto kk:tmpp)num[j].insert(kk);
      }
    }
  }
  int ans = 0;
  for(i=0;i<n;i++){
    if(chk[i]==false)ans++;
  }
  cout << ans << endl;
}
