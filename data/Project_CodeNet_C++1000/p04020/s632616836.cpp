#include <bits/stdc++.h>

using namespace std;

int main(){
  long long n, a[100009];
  cin >> n;
  for(int i=1;i<=n;i++)cin >> a[i];
  long long ans=0;
  for(int i=1;i<=n;i++){
    ans += a[i]/2;
    if(i<n&&(a[i]%2==1)&&a[i+1]>0){
      a[i+1]--;
      ans++;
    }
  }
  cout << ans << endl;
}

