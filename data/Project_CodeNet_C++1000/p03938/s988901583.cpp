#include<iostream>
using namespace std;
typedef long long ll;
signed main(){
  ll n;
  cin >> n;
  ll p[n],r[n];
  for(int i=0;i<n;i++){
    cout << 30000*(i+1)<<" ";
  }
  cout << endl;
  for(int i=0;i<n;i++){
    cin >> p[i];
    p[i]--;
    r[p[i]]=i+1;
  }
  for(int i=0;i<n;i++){
    cout << 30000*(n-(i+1))+r[i]<<" ";
  }
  cout << endl;
}
