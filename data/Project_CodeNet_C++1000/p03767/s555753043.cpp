#include <bits/stdc++.h>
#define P pair<int, int>

using namespace std;
const int INF=1e5;

int main(){
  long long n, a[3*100009];
  cin >> n;
  for(int i=0;i<3*n;i++)cin >> a[i];
  sort(a, a+3*n);
  long long sm=0;
  for(int i=n;i<3*n;i+=2)sm+=a[i];
  cout << sm << endl;
}

