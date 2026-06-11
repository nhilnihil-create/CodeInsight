#include <bits/stdc++.h>
using namespace std;
#define int long long
bool used[100001]={};
vector<int> hen[100001];
int grundy(int a){
  used[a]=true;
  int ans=0;
  for(int i=0;i<hen[a].size();i++){
    if(!used[hen[a][i]])ans^=(1+grundy(hen[a][i]));
  }
  return ans;
}
signed main() {
int n;
cin>>n;
int a,b;
for(int i=0;i<n-1;i++){
  cin>>a>>b;a--;b--;
  hen[a].push_back(b);
  hen[b].push_back(a);
}
if(grundy(0))cout<<"Alice"<<endl;
else cout<<"Bob"<<endl;


return 0;
}
