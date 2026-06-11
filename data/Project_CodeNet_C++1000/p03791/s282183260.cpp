#include<iostream>
#include<algorithm>

using namespace std;
typedef long long Int;
#define MOD 1000000007
Int res = 1;
Int n, x;
int main(){
  cin >> n;
  int last = -1;
  int gap= 0;
  for(int i = 0;i < n;i++){
    cin >> x;
    res = res * ( i + 1 - gap) % MOD;
    if(last + 2 > x) gap++;
    else last += 2;
  }
  cout << res << endl;
  return 0;
}
  
