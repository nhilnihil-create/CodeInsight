#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(x) (x).begin,(x).end()

int main(){
  vector<int> a(3);
  rep(i,3){cin >> a[i];}
  sort(a.begin(),a.end());
  
  int kind = 1;
  for(int i = 1; i < 3; i++){
    if(a[i] != a[i-1]) kind++;
  }
  
  cout << kind << endl;
}