#include <bits/stdc++.h>
#define rep(i,a,n) for(int i =a; i<n; i++) 
#define ll long long
#define MOD 1000000007
using namespace std;

int sum[5001][5001];

int main() {
  int a,b,c; cin >> a >> b >> c;
  cout << a+b+c-max(a,max(b,c)) << endl;
}