#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;
  cin>>n;
  int p=0,q=1;
  while(q*2-1<=n) q*=2,p++;
  vector<int> ans;
  for(int i=0;i<p;i++) ans.push_back(i+1);
  q=n-(q-1);
  int x=1;
  for(int i=p-1;i>=0;i--){
    if((q>>i)&1){
      ans.insert(ans.begin()+i,p+x);
      x++;
    }
  }
  q=ans.size();
  for(int i=0;i<q;i++) ans.push_back(i+1);
  cout<<ans.size()<<endl;
  for(int i=0;i<(int)ans.size();i++)
    cout<<ans[i]<<" \n"[i==(int)ans.size()-1];
  return 0;
}
