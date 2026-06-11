//In The Name Of GOD
#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int inf = 2000000000;
const int maxn = 40000;
#define ll long long
#define pb push_back
#define mp make_pair
#define IO ios_base::sync_with_stdio(false);
int main(){
  IO;
  int n;
  cin>>n;
  int p[n],A[n],B[n];
  for(int i=0;i<n;i++){
    cin>>p[i];
    p[i]-=1;
  }
  for(int i=0;i<n;i++){
    A[i]=(i+1)*maxn;
  }
  for(int i=0;i<n;i++){
    B[p[i]]=(p[i]+1)*(-maxn)+i;
  }
  int mini=0;
  for(int i=0;i<n;i++){
    mini=min(B[i],mini);
  }
  for(int i=0;i<n;i++){
    B[i]+=-mini+1;
  }
  for(int i=0;i<n;i++){
    cout<<A[i]<<' ';
  }
  cout<<endl;
  for(int i=0;i<n;i++){
    cout<<B[i]<<' ';
  }
  cout<<endl;
}
