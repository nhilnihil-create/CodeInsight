#include <bits/stdc++.h>
#define P pair<int, int>

using namespace std;
const int INF=1e5;

long long gcd(long long a, long long b){
  if(b==0)return a;
  return gcd(b, a%b);
}

int main(){
  long long n, k, a[100009];
  cin >> n >> k;
  for(int i=0;i<n;i++)cin >> a[i];
  long long _gcd = a[0];
  for(int i=1;i<n;i++)_gcd = gcd(_gcd, a[i]);
  for(int i=0;i<n;i++){
    if(a[i]>=k && (a[i]-k)%_gcd==0){
      cout << "POSSIBLE" << endl;
      return 0;
    }
  }
  cout << "IMPOSSIBLE" << endl;
}
