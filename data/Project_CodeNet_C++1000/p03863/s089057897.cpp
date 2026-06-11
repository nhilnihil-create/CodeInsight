#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  string s;
  cin>>s;
  int n=s.size();
  if(n%2==1 && s[0]==s[n-1]) cout<<"Second"<<endl;
  else if(n%2==0 && s[0]!=s[n-1]) cout<<"Second"<<endl;
  else cout<<"First"<<endl;
}