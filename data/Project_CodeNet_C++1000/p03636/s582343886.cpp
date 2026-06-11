#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<=(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;
typedef vector<string> vs;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  int n=(int)s.size();

  cout << s[0] << n-2 << s[n-1] << endl;

  return 0;
}