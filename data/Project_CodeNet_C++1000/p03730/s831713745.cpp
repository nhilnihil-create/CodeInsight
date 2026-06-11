#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<=(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b, c;
  cin >> a >> b >> c;
  int n=a;
  string ans="NO";
  rep(i, a*b){
    if(n%b==c){
      ans="YES";
      break;
    }
    n+=a;
  }

  cout << ans << endl;

  return 0;
}