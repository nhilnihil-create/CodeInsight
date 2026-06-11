#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;


int main(){
  int x,a,b;
  cin >> x >> a >> b;
  
  if(b >= x+a+1) cout << "dangerous" << endl;
  if(x+a >= b && b > a) cout << "safe" << endl;
  if(a >= b) cout << "delicious" << endl;
}