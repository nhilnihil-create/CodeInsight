#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);

  int K,T;
  cin >> K >> T;

  int max_val = 0;
  for(int i = 0; i < T; i++){
    int tmp;
    cin >> tmp;
    if(max_val < tmp) max_val = tmp;
  }

  int ans = 0;
  int tmp = max_val - 1 - (K-max_val);
  if(tmp > 0) ans = tmp;
  cout << ans << endl;
}
