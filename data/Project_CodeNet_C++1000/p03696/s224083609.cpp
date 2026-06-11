#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
const ll INF = 1001001001;
const ll MOD = 1e9 + 7;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int cnt1 = 0, cnt2 = 0, lo = 0, ro = 0;
  for(int i = 0; i<n; i++){
    if(s.at(i) == '(') cnt1++;
    else cnt2++;
    lo = max(lo, cnt2 - cnt1);
  }
  cnt1=0;cnt2 =0 ;
  for(int i = n-1; i>=0; i--){
    if(s.at(i) == '(') cnt1++;
    else cnt2++;
    ro = max(ro, cnt1 - cnt2);
  }
  while(lo){
    s = '(' + s;
    lo--;
  }
  while(ro){
    s = s + ')';
    ro--;
  }
  cout << s <<endl;
}