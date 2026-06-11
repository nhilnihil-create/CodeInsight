#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());
#define vecmin(A) *min_element(A.begin(),A.end());
#define vecmax(A) *max_element(A.begin(),A.end());
typedef long long ll;

int main(){
  ll x;
  cin >> x;
  ll y = x%11;
  ll step = x/11;
  if(y == 0) cout << step*2 << endl;
  if(0<y && y<=6) cout << step*2+1 << endl;
  if(6<y && y<=10) cout << step*2+2 << endl;
}