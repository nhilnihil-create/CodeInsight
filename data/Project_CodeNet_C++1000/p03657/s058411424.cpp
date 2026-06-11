#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int a,b;
  cin >> a >> b;
  
  bool flag = 0;
  
  if(a%3 == 0) flag = 1;
  if(b%3 == 0) flag = 1;
  if((a+b)%3 == 0) flag = 1;
  
  if(flag) cout << "Possible" << endl;
  else cout << "Impossible" << endl;
}