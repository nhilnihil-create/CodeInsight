#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,p;
  cin>>n>>p;
  int o=0;
  int e=0;
  for(int _=0;_<n;_++){
    int a;
    cin>>a;
    if(a%2==1)
      o++;
    else
      e++;
  }
  vector<vector<int64_t>> c(o+1,vector<int64_t>(o+1,1));
  for(int i=1;i<=o;i++)
    for(int j=1;j<i;j++)
      c[i][j]=c[i-1][j-1]+c[i-1][j];
  int64_t s=0;
  for(int i=0;i<=o;i++)
    s+=(i%2==p?c[o][i]:0);
  for(int i=0;i<e;i++)
    s*=2;
  cout<<s<<endl;
}