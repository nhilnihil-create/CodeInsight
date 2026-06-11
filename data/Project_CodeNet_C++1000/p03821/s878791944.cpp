#include <bits/stdc++.h>

using namespace std;

int main(){
  long long n, a[100009], b[100009];
  cin >> n;
  for(int i=0;i<n;i++)cin >> a[i] >> b[i];
  long long sm=0;
  for(int i=n-1;i>=0;i--){
    if((a[i]+sm)%b[i]==0)continue;
    sm += ((a[i]+sm-1)/b[i]+1)*b[i] - (a[i]+sm);
  }
  cout << sm << endl;
}

