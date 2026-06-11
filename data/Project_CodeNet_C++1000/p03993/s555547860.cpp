#include <bits/stdc++.h> 
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
typedef long long ll;

int main(){
  int n; cin>>n;
  int a[n];
  rep(i,n){
    cin>>a[i];
    a[i]--;
  }
  int count=0;
  rep(i,n){
    if(i==a[a[i]]) count++;
  }
  cout<<count/2<<endl;
}