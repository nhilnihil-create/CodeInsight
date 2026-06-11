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
  for(int i = 0 ; i < s.size(); i ++ ){
    cout << s[i];
    if(i==3)
      cout << " ";
  }
  cout << "\n";
  return 0;
}
