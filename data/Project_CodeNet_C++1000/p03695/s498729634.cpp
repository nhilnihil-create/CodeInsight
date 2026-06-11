#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  bool p[8];
  int q=0;
  rep(i,0,8) p[i]=false;
  rep(i,0,n){
    int a;
    cin>>a;
    if(a<3200) p[a/400]=true;
    else q++;
  }
  int mi=0;
  rep(i,0,8){
    if(p[i]) mi++;
  }
  cout<<max(mi,1)<<' '<<mi+q<<endl;
}