#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,ans=0;
  cin >> n >> m;
  vector<int> x(n),mod(m,0),num(100010,0);
  for(int i=0;i<n;i++){
    cin >> x[i];
    mod[x[i]%m]++;
    num[x[i]]++;
  }
  for(int i=0;i*2<=m;i++){
    if(i*2%m==0){
      ans+=mod[i]/2;
      mod[i]%=2;
    }
    else{
      int p=min(mod[i],mod[m-i]);
      ans+=p;
      mod[i]-=p;
      mod[m-i]-=p;
    }
  }
  for(int i=1;i<100001;i++){
    if(mod[i%m]>1 && num[i]>1){
      ans+=min(mod[i%m]/2,num[i]/2);
      mod[i%m]-=min(mod[i%m]/2*2,num[i]/2*2);
    }
  }
  cout << ans << endl;
}