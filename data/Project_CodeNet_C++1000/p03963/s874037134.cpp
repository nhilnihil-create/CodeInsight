#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

int main(){
  int n, k; 
  cin >> n >> k;

  int ans = 1;
  ans *=k;
  ans *= pow(k-1, n-1);
  cout << ans << endl;

   return 0;
}