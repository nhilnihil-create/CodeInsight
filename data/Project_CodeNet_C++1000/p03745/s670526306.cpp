#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
char c[4][4];

int main(){
  int n;
  cin>> n;
  vector<ll>a(n); 
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  ll ans = 0;
  for(int i=0; i<n; i++){
    if(i+1<n&&a[i]==a[i+1]){
      while(a[i]==a[i+1])i++;
    }
    if(i+1<n&&a[i] < a[i+1]){
      while(a[i] <= a[i+1]){
	i++;
      }
    }else if(i+1<n&&a[i] >= a[i+1]){
      while(a[i] >= a[i+1])i++;
    }
    ans++;
  }
  cout<< ans << endl;
  return 0;
}
