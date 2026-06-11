#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int h,w;
  cin>>h>>w;
  int a[12]={0,2,0,1,0,1,0,0,1,0,1,0};
  if(a[h-1]==a[w-1]) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}