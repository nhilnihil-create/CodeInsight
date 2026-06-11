#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  ll X,t;
  cin >> X >> t;
  cout << (X-t >= 0 ? X-t : 0) << endl;
}
