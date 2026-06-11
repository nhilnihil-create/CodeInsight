#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll = long long int;
using namespace std;
ll mod=1e9+7;

int main(){
  int a[4];
  rep(i,4){a[i]=0;}
  string s;
  cin >> s;
  int q=s.size();
  rep(i,q){
    if(s[i]=='N')a[0]++;
    if(s[i]=='W')a[1]++;
    if(s[i]=='S')a[2]++;
    if(s[i]=='E')a[3]++;
  }
  bool ans=1;
  if(a[0]>0 && a[2]==0 || a[0]==0 && a[2]>0){ans=0;}
  if(a[1]>0 && a[3]==0 || a[1]==0 && a[3]>0){ans=0;}
  if(ans){cout << "Yes" << endl;}else{cout << "No" << endl;}
}