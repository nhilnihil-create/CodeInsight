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
  int a,b;
  cin >> a >> b;
  int aa = (a+11)%13;
  int bb = (b+11)%13;
  if(aa > bb) cout << "Alice" << endl;
  if(aa == bb) cout << "Draw" << endl;
  if(aa < bb) cout << "Bob" << endl;
}