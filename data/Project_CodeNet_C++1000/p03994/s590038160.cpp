#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  string s;
  cin >> s;
  int k;
  cin >> k;
  for(char &x : s){
    if(x == 'a') continue;
    if('z' - x + 1 <= k){
      k -= 'z' - x + 1;
      x = 'a';
    }
  }
  k %= 26;
  for(int i = s.size() - 1; i >= 0 ; i -- ){
    s[i] += k;
    k = 0;
  }
  cout << s << "\n";
  return 0;
}
