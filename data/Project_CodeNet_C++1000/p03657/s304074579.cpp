#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int a,b;
  cin>>a>>b;
  if(a%3==0 || b%3==0 || (a+b)%3==0) cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
}