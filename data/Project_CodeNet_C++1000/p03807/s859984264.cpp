#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  rep(i,n)cin >> a[i];

  int numOdd=0;
  rep(i,n)if(a[i]%2!=0)numOdd++;
  if(numOdd%2==0)cout << "YES" << endl;
  else cout << "NO" << endl; 
}
