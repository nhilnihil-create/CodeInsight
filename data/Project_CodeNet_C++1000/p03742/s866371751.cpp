#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i<n;i++)

int main(){
  ll x,y; cin>>x>>y;
  if((max(x,y)-min(x,y))<2) cout<<"Brown"<<endl;
  else cout<<"Alice"<<endl;
}
