#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  int p=0,q=0,r=0;
  rep(i,0,n){
    int a;
    cin>>a;
    if(a%2!=0){
      p++;
    }
    else if(a%4==0){
      r++;
    }
    else{
      q++;
    }
  }
  if(p<=r) cout<<"Yes"<<endl;
  else if(p==r+1 && q==0) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
