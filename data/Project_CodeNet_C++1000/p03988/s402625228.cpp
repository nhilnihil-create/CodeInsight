#include "bits/stdc++.h"
using namespace std;
#define int long long
#define endl '\n'
int mod=1e9+7;
int mod2=998244353;

signed main(){
  int n;
  cin>>n;
  vector<int> a(n);
  vector<int> ch(101,0);
  for(int i=0;i<n;i++){
    cin>>a[i];
    ch[a[i]]++;
  }
  sort(a.begin(),a.end(),greater<int>());
  if(a[0]%2==0){
    bool f=true;
    int sum=0;
    for(int i=a[0]/2+1;i<=a[0];i++){
      if(ch[i]<2)f=false;
      sum+=ch[i];
    }
    if(f&&sum==n-1&&ch[a[0]/2]==1)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
  }else{
    bool f=true;
    int sum=0;
    for(int i=a[0]/2+1;i<=a[0];i++){
      if(ch[i]<2)f=false;
      sum+=ch[i];
    }
    if(f&&sum==n&&ch[a[0]/2+1]==2)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
  }
}
