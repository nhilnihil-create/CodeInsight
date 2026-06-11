#include<bits/stdc++.h>
using namespace std;
long long int gcd(long long int x, long long int y){
 long long int tmp;
 long long int r;
 if(x > y){
    tmp = x;
    x = y;
    y = tmp;
  }
  r = y % x;
  while(r!=0){
    y = x;
    x = r;
    r = y % x;
  }
  return x;
}
int main(){
    int n;
    cin >> n;
    long long int t[n];
    for(int i=0;i<n;i++)cin >> t[i];
    if(n==1){
        cout << t[0];
        return 0;
    }
    long long int ans=t[0]/gcd(t[0],t[1])*t[1];
    for(int i=2;i<n;i++)ans=ans/gcd(ans,t[i])*t[i];
    cout << ans;
}